#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;

int n, m, query;
vector<int> g[MAXN], dag[MAXN];
int id[MAXN], low[MAXN], disc[MAXN], hitung, komponen;
bool cek[MAXN];

stack<int> st;
bitset<MAXN> reach[MAXN];

void tarjan(int u) {
  disc[u] = low[u] = ++hitung;
  st.push(u);
  cek[u] = true;

  for (int v : g[u]) {
    if (!disc[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (cek[v]) {
      low[u] = min(low[u], disc[v]);
    }
  }

  if (low[u] == disc[u]) {
    komponen++;
    while (!st.empty()) {
      int v = st.top(); st.pop();
      cek[v] = false;
      id[v] = komponen;
      if (v == u) break;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
  }

  for (int i = 1; i <= n; i++) {
    if (!disc[i]) tarjan(i);
  }

  for (int u = 1; u <= n; u++) {
    for (int v : g[u]) {
      if (id[u] != id[v]) {
        dag[id[u]].push_back(id[v]);
      }
    }
  }

  vector<int> indeg(komponen+1, 0);
  for (int u = 1; u <= komponen; u++) {
    for (int v : dag[u]) indeg[v]++;
  }

  queue<int> q;
  for (int i = 1; i <= komponen; i++) {
    if (!indeg[i]) q.push(i);
  }

  for (int i = 1; i <= komponen; i++){
    reach[i][i] = 1;
  }  

  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : dag[u]) {
      reach[v] |= reach[u];
      if (--indeg[v] == 0) q.push(v);
    }
  }

  cin >> query;
  while (query--) {
    int f, t;
    cin >> f >> t;
    if (reach[id[t]][id[f]]) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}