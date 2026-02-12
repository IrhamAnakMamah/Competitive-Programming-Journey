#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n, m;
  cin >> n >> m;

  vector<vector<pair<ll,ll>>> adj(n+1);
  for (int i = 0; i < m; i++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    adj[x].push_back({y, z});
    adj[y].push_back({x, z});
  }
  
  vector<ll> p(n+1, -1);
  vector<ll> d(n+1, 1e18);

  auto dijkstra = [&] (int s){
    d[s] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {
      auto[dist, v] = pq.top();
      pq.pop();
      if(dist != d[v]){
        continue;
      }

      for(auto [to, len] : adj[v]){
        if(d[v] + len < d[to]){
          d[to] = d[v] + len;
          p[to] = v;
          pq.push({d[to], to});
        }
      }
    }
    
  };

  dijkstra(1);
  vector<ll> ans;
  for(int u = n; ; u = p[u]){
    ans.push_back(u);
    if(u == 1 || p[u] == -1){
      break;
    }
  }
  if(ans.front() == n && ans.back() == 1){
    reverse(ans.begin(), ans.end());
    for(auto x : ans){
      cout << x << " ";
    }
  }else{
    cout << -1;
  }
  cout << endl;
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
  return 0;
}