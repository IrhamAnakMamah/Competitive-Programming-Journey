#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// Variabel global untuk algoritma Tarjan
vector<vector<int>> adj;
vector<int> disc, low; 
vector<bool> onStack;
stack<int> st;
int timer = 0;

// Variabel untuk SCC
vector<int> scc_id;
int scc_count = 0;

// Fungsi rekursif Tarjan untuk menemukan SCC
void tarjan(int u) {
    disc[u] = low[u] = ++timer;
    st.push(u);
    onStack[u] = true;

    for (int v : adj[u]) {
        if (disc[v] == 0) { // Jika v belum dikunjungi
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (onStack[v]) { // Jika v ada di stack, ini adalah back-edge
            low[u] = min(low[u], disc[v]);
        }
    }

    // Jika u adalah akar dari sebuah SCC
    if (low[u] == disc[u]) {
        scc_count++;
        while (true) {
            int node = st.top();
            st.pop();
            onStack[node] = false;
            scc_id[node] = scc_count;
            if (node == u) break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    disc.resize(N+1, 0);
    low.resize(N+1, 0);
    onStack.resize(N+1, 0);

    vector<long long> b(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> b[i];
    }

    vector<long long> w(K);
    for (int i = 0; i < K; ++i) {
        cin >> w[i];
    }

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // 1. Jalankan algoritma Tarjan untuk menemukan semua SCC
    for (int i = 1; i <= N; ++i) {
        if (disc[i] == 0) {
            tarjan(i);
        }
    }

    // 2. Analisis graf kondensasi
    //    - Temukan biaya dasar minimum untuk setiap SCC
    //    - Hitung in-degree untuk setiap SCC
    vector<long long> min_b_scc(scc_count + 1, -1);
    vector<int> scc_indegree(scc_count + 1, 0);

    for (int i = 1; i <= N; ++i) {
        if (min_b_scc[scc_id[i]] == -1 || b[i] < min_b_scc[scc_id[i]]) {
            min_b_scc[scc_id[i]] = b[i];
        }
    }

    for (int u = 1; u <= N; ++u) {
        for (int v : adj[u]) {
            if (scc_id[u]!= scc_id[v]) {
                scc_indegree[scc_id[v]]++;
            }
        }
    }

    // 3. Identifikasi SCC sumber dan kumpulkan biaya minimumnya
    vector<long long> source_scc_costs;
    for (int i = 1; i <= scc_count; ++i) {
        if (scc_indegree[i] == 0) {
            source_scc_costs.push_back(min_b_scc[i]);
        }
    }

    int P = source_scc_costs.size();

    // 4. Pemeriksaan kelayakan
    if (P > K) {
        cout << -1 << endl;
        return 0;
    }
    
    // Jika tidak ada desa atau tidak ada SCC sumber, biaya adalah 0
    if (P == 0) {
        cout << 0 << endl;
        return 0;
    }

    // 5. Hitung biaya total minimum
    sort(source_scc_costs.begin(), source_scc_costs.end()); // Urutkan biaya dasar menaik
    sort(w.begin(), w.end()); // Urutkan biaya penjaga menaik

    long long total_cost = 0;
    for (int i = 0; i < P; ++i) {
        // Pasangkan biaya dasar terbesar dengan penjaga termurah, dst.
        // Ini setara dengan memasangkan b_terurut[i] dengan w_terurut[P-1-i]
        // Atau, lebih mudah, b_terurut_menaik[i] dengan w_terurut_menurun[i]
        total_cost += source_scc_costs[i] * w[P - 1 - i];
    }

    cout << total_cost << endl;

    return 0;
}