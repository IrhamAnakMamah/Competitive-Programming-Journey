#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <stack>
#include <tuple>

using namespace std;

const int MAXN = 200005;

long long powers[MAXN];
long long answers[MAXN];

// Enum untuk menandai tipe perubahan yang disimpan
enum ChangeType { PARENT, SIZE, MIN_VAL, MAX_VAL };

// Struct untuk menyimpan histori perubahan secara type-safe
struct Change {
    int index;
    long long old_val;
    ChangeType type;
};

// DSU dengan dukungan rollback yang telah diperbaiki
struct DSU_Rollback {
    vector<int> parent;
    vector<int> sz;
    vector<long long> min_val;
    vector<long long> max_val;
    stack<Change> history;

    DSU_Rollback(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n + 1, 1);
        min_val.resize(n + 1);
        max_val.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            min_val[i] = powers[i];
            max_val[i] = powers[i];
        }
    }

    int find(int i) {
        while (i != parent[i]) {
            i = parent[i];
        }
        return i;
    }

    void unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);

        if (root_u != root_v) {
            if (sz[root_u] < sz[root_v]) swap(root_u, root_v);
            
            // Catat keadaan sebelum diubah dengan aman
            history.push({root_v, (long long)parent[root_v], PARENT});
            history.push({root_u, (long long)sz[root_u], SIZE});
            history.push({root_u, min_val[root_u], MIN_VAL});
            history.push({root_u, max_val[root_u], MAX_VAL});
            
            // Lakukan union
            parent[root_v] = root_u;
            sz[root_u] += sz[root_v];
            min_val[root_u] = min(min_val[root_u], min_val[root_v]);
            max_val[root_u] = max(max_val[root_u], max_val[root_v]);
        }
    }
    
    // Mengembalikan satu perubahan berdasarkan tipenya
    void rollback() {
        Change c = history.top();
        history.pop();
        switch (c.type) {
            case PARENT:
                parent[c.index] = c.old_val;
                break;
            case SIZE:
                sz[c.index] = c.old_val;
                break;
            case MIN_VAL:
                min_val[c.index] = c.old_val;
                break;
            case MAX_VAL:
                max_val[c.index] = c.old_val;
                break;
        }
    }

    long long get_stability(int u) {
        int root = find(u);
        if (sz[root] <= 1) return 0;
        return max_val[root] - min_val[root];
    }
};

// --- Segment Tree untuk Kueri Offline ---
vector<pair<int, int>> seg_tree[4 * MAXN];
vector<pair<int, int>> queries_at_time[MAXN]; // {node_u, query_index}

void add_edge_to_segtree(int u, int v, int l, int r, int node, int node_l, int node_r) {
    if (r < node_l || l > node_r) {
        return;
    }
    if (l <= node_l && node_r <= r) {
        seg_tree[node].push_back({u, v});
        return;
    }
    int mid = node_l + (node_r - node_l) / 2;
    add_edge_to_segtree(u, v, l, r, 2 * node, node_l, mid);
    add_edge_to_segtree(u, v, l, r, 2 * node + 1, mid + 1, node_r);
}

// --- DFS di Segment Tree dengan logika rollback yang disederhanakan ---
void dfs_solve(int node, int l, int r, DSU_Rollback& dsu) {
    // Catat ukuran history sebelum melakukan perubahan
    size_t history_size_before = dsu.history.size();

    // 1. Aplikasikan semua edge yang ada di node segment tree ini
    for (auto& edge : seg_tree[node]) {
        dsu.unite(edge.first, edge.second);
    }

    // 2. Jika ini adalah leaf, jawab kueri pada waktu ini
    if (l == r) {
        for (auto& query : queries_at_time[l]) {
            answers[query.second] = dsu.get_stability(query.first);
        }
    } else {
    // 3. Jika bukan leaf, lanjutkan ke anak-anaknya
        int mid = l + (r - l) / 2;
        dfs_solve(2 * node, l, mid, dsu);
        dfs_solve(2 * node + 1, mid + 1, r, dsu);
    }
    
    // 4. Rollback semua perubahan yang dibuat di level ini
    while (dsu.history.size() > history_size_before) {
        dsu.rollback();
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	//   freopen("test.in", "r", stdin);
	//   freopen("out.out", "w", stdout);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> powers[i];
    }

    map<pair<int, int>, int> temp_edge_start_time;
    vector<tuple<int, int, int, int>> edge_lifetimes; // u, v, start, end
    int query_count = 0;

    for (int t = 1; t <= q; ++t) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            edge_lifetimes.emplace_back(u, v, t, q);
        } else if (type == 2) {
            int u, v;
            cin >> u >> v;
            if (u > v) swap(u, v);
            temp_edge_start_time[{u, v}] = t;
        } else if (type == 3) {
            int u, v;
            cin >> u >> v;
            if (u > v) swap(u, v);
            int start_time = temp_edge_start_time.at({u, v});
            edge_lifetimes.emplace_back(u, v, start_time, t - 1);
            temp_edge_start_time.erase({u, v});
        } else { // type 4
            int u;
            cin >> u;
            queries_at_time[t].push_back({u, query_count++});
        }
    }
    
    for(auto const& [edge, start_time] : temp_edge_start_time) {
        edge_lifetimes.emplace_back(edge.first, edge.second, start_time, q);
    }

    for (const auto& edge : edge_lifetimes) {
        int u, v, start, end;
        tie(u, v, start, end) = edge;
        if (start <= end) {
            add_edge_to_segtree(u, v, start, end, 1, 1, q);
        }
    }

    DSU_Rollback dsu(n);
    if (q > 0) {
       dfs_solve(1, 1, q, dsu);
    }

    // cout << "TEST" << endl;
    for (int i = 0; i < query_count; ++i) {
        cout << answers[i] << "\n";
    }

    return 0;
}