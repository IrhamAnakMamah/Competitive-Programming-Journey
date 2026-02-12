#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll inf = 2e18;

struct Bridges{
  int b;
  ll c, t;
  bool kondisi;
};

void solve(){
  int n, k;
  cin >> n >> k;

  vector<vector<Bridges>> adj(n+1);
  vector<ll> d(n+1, inf);
  for (int i = 0; i < k; i++)
  {
    int a,b;
    cin >> a >> b;

    ll c, t;
    cin >> c >> t;

    adj[a].push_back({b,c,t,0});
    adj[b].push_back({a,c,t,1});
  }
  
  int x, y;
  cin >> x >> y;

  auto search = [&] (int from){
    using pll = pair<ll,ll>;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, from});
    d[from] = 0;
    while (!q.empty()) {
      int v = q.top().second;
      ll time = q.top().first;
      q.pop();
      if (time != d[v])
          continue;

      for (auto [b,c,t,k] : adj[v]) {
        int to = b;
        ll cost = c;
        ll flip = t;
        bool kondisi = k;
        ll temp = time/flip;
        if((temp&1) != kondisi){
          cost += (flip - (time % flip));
        }
        
        if (d[v] + cost < d[to]) {
          d[to] = d[v] + cost;
          q.push({d[to], to});
        }
      }
    }
  };

  search(x);
  cout << (d[y] == inf ? -1 : d[y]) << endl;
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
