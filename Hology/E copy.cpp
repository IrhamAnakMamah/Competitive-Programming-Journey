#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;

int X, Y, Q;
vector<int> g[MAXN];
int compId[MAXN], low[MAXN], disc[MAXN], timer, compCount;
bool inStack[MAXN];
stack<int> st;

vector<int> dag[MAXN];
bitset<MAXN> reach[MAXN];

// Tarjan untuk SCC
void tarjan(int u) {
    disc[u] = low[u] = ++timer;
    st.push(u);
    inStack[u] = true;

    for (int v : g[u]) {
        if (!disc[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u]) {
        compCount++;
        while (true) {
            int v = st.top(); st.pop();
            inStack[v] = false;
            compId[v] = compCount;
            if (v == u) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> X >> Y;
    for (int i = 0; i < Y; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    // Tarjan
    for (int i = 1; i <= X; i++) {
        if (!disc[i]) tarjan(i);
    }

    // Build DAG dari SCC
    for (int u = 1; u <= X; u++) {
        for (int v : g[u]) {
            if (compId[u] != compId[v]) {
                dag[compId[u]].push_back(compId[v]);
            }
        }
    }

    // Topo sort SCC DAG
    vector<int> indeg(compCount+1, 0);
    for (int u = 1; u <= compCount; u++) {
        for (int v : dag[u]) indeg[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= compCount; i++) if (!indeg[i]) q.push(i);

    // Inisialisasi reach
    for (int i = 1; i <= compCount; i++) reach[i][i] = 1;

    // Propagasi reachability (transitive closure dengan topo order)
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : dag[u]) {
            reach[v] |= reach[u];
            if (--indeg[v] == 0) q.push(v);
        }
    }
    cin >> Q;
    while (Q--) {
        int f, t;
        cin >> f >> t;
        if (reach[compId[t]][compId[f]]) cout << "YES\n";
        else cout << "NO\n";
    }
}