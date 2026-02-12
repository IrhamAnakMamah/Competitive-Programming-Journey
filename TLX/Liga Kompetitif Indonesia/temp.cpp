#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 998244353;

void solve(){
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n+1);
  vector<bool> vis(n+1, 0);
  
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  for (int i = 1; i <= n; i++)
  {
    sort(adj[i].begin(), adj[i].end());
  }
  

  ll cnt = 0;
  auto bfs = [&] (int xx){
    queue<int> q;
    q.push(xx);
    while (!q.empty())
    {
      int u = q.front();
      vis[u] = 1;
      q.pop();
      cnt = (cnt + 1) % mod;
      for(auto v : adj[u]){
        if(!vis[v]){
          q.push(v);
        }
      }
    }
    
  };

  bfs(1);
  
  cout << cnt << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
  }
  
}