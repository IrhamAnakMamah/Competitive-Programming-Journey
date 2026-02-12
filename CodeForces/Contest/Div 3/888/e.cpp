#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<ll> a;
vector<bool> vis;
vector<vector<int>> adj;

ll dfs(int u){
  if(vis[u] || adj[u].size() == 0){
    vis[u] = 1;
    return a[u];
  }
  
  vis[u] = 1;
  
  ll res = 0;
  for(auto v : adj[u]){
    // cout << "TEST " << v << " " << u << endl;
    res += dfs(v);
  }

  a[u] = min(a[u], res);
  return a[u];
}

void solve(){
  int n, m;
  cin >> n >> m;
  adj.resize(n);
  vis.resize(n, 0);
  a.resize(n);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  for (int i = 0; i < m; i++)
  {
    int x;
    cin >> x;
    x--;
    a[x] = 0;
  }
  
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    for (int j = 0; j < x; j++)
    {
      int y;
      cin >> y;
      y--;
      adj[i].push_back(y);
    }
  }

  for (int i = 0; i < n; i++)
  {
    cout << dfs(i) << " ";
  }
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;

  while (t--)
  {
    a.clear();
    vis.clear();
    adj.clear();
    solve();
  }
  
  return 0;
}
