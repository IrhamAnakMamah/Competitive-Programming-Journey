#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Edge {
  int u, v;
  ll w;
};

void solve(){
  int n, m;
  cin >> n >> m;

  vector<Edge> edges;
  for(int i = 0; i < m; i++){
    int u, v;
    ll w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }

  vector<ll> d(n + 1);
  vector<int> p(n + 1, -1);
  int x = -1;

  for(int i = 0; i < n; i++){
    x = -1;
    for(auto e : edges){
      if(d[e.u] + e.w < d[e.v]){
        d[e.v] = d[e.u] + e.w;
        p[e.v] = e.u;
        x = e.v;
      }
    }
  }

  if(x == -1){
    cout << "NO" << endl;
  }else{
    for(int i = 0; i < n; i++){
      x = p[x];
    }

    vector<int> cycle;
    for(int v = x;; v = p[v]){
      cycle.push_back(v);
      if(v == x && cycle.size() > 1) break;
    }
    reverse(cycle.begin(), cycle.end());

    cout << "YES" << endl;
    for(auto c : cycle){
      cout << c << " ";
    }
    cout << endl;
  }
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