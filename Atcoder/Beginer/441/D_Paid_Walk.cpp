#include <bits/stdc++.h>
using namespace std;

using ll = long long;

set<int> ans;
ll n, m, l, s, t;
vector<vector<pair<ll,ll>>> adj;

void dfs(ll u, ll sum, ll trav){
  if(trav == l){
    if(sum >= s && sum <= t){
      ans.insert(u);
    }
    return;
  }
  for(auto [x,y] : adj[u]){
    dfs(x, sum + y, trav + 1);
  }
}

int main(){
  cin >> n >> m >> l >> s >> t;

  adj.resize(n+1);
  for (int i = 0; i < m; i++)
  {
    ll x, y, c;
    cin >> x >> y >> c;
    adj[x].push_back({y, c});
  }
  
  dfs(1, 0, 0);
  for(auto x : ans){
    cout << x << " ";
  }
  cout << endl;
}