#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  int n,m,q;
  cin >> n >> m >> q;

  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  ll b[m];
  for (int i = 0; i < m; i++)
  {
    cin >> b[i];
  }
  sort(b, b + m);
  
  vector<vector<int>> adj(n);
  vector<ll> listrik;

  for (int i = 0; i < q; i++)
  {
    int x,y;
    cin >> x >> y;
    x--,y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  vector<bool> vis(n+1, 0);
  
  auto bfs = [&] (int i){
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    ll mn = a[i];
    while (!q.empty())
    {
      int z = q.front();
      q.pop();
      for(auto x : adj[z]){
        if(!vis[x]){
          mn = min(mn,a[x]);
          vis[x] = 1;
          q.push(x);
        }
      }
    }
    listrik.push_back(mn);
  };
  
  for (int i = 0; i < n; i++)
  {
    if(!vis[i]){
      bfs(i);
    }
  }
  
  if(listrik.size() > m){
    cout << -1 << endl;
  }else{
    ll ans = 0;
    sort(listrik.begin(), listrik.end(), greater<int>());
    for (int i = 0; i < listrik.size(); i++)
    {
      ans += listrik[i] * b[i];
    }
    cout << ans << endl;
  }
}