#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
ll a[MAXN];
vector<ll> col[2];

void dfs(int u, int p, int c) {
  col[c].push_back(a[u]);
  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u, 1 - c);
    }
  }
}

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) 
  {
    cin >> a[i];
    adj[i].clear();
  }

  for (int i = 0; i < n - 1; i++) 
  {
    int u, v;
    cin >> u >> v;
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  col[0].clear();
  col[1].clear();

  dfs(0, -1, 0);

  ll res = 0;

  for (int i = 0; i < 2; i++) 
  {
    vector<ll> neg;
    for (ll val : col[i]) {
      if (val >= 0) {
        res += val;
      } else {
        neg.push_back(val);
      }
    }

    if (neg.size() % 2 != 0) {
      sort(neg.begin(), neg.end());
      res += neg.back();
    }
  }

  cout << res << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
      solve();
  }
  return 0;

}