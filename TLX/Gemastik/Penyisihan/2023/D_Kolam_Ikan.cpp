#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  int n,q,k;
  cin >> n >> q >> k;
  ll a[n+1];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i+1];
  }
  
  vector<vector<ll>> adj(n+1);
  vector<bool> vis(n+2, 0);

  for (int i = 0; i < q; i++)
  {
    ll x,y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  
  auto bfs = [&] (ll input){
    queue<ll> q;
    vis[input] = 1;
    q.push(input);
    ll sum = 0;
    ll mn = a[input];

    while (!q.empty())
    {
      ll aa = q.front();
      q.pop();
      sum++;
      for(auto x : adj[aa]){
        if(!vis[x]){
          vis[x] = 1;
          q.push(x);
          mn = min(a[x],mn);
        }
      }
    }
    
    pair<ll,ll> ans = {mn,sum};
    return ans;
  };

  vector<pair<ll,ll>> cache;
  
  for (int i = 1; i <= n; i++)
  {
    if(!vis[i]){
      auto x = bfs(i);
      cache.push_back(x);
    }
  }
  sort(cache.begin(), cache.end());

  vector<pair<ll,ll>> ans;
  ans.push_back({cache[0].first * cache[0].second, 1LL * 0});
  // mencari nilai terbesar antara harga sebelum dirubah - harga setelah dirubah,
  for (int i = 1; i < cache.size(); i++)
  {
    ans.push_back({cache[i].first * cache[i].second - cache[0].first * cache[i].second, cache[i].first * cache[i].second});
  }
  sort(ans.begin(), ans.end(), greater<>());
  ll jumlah = ans[0].first;
  for (int i = 1; i < ans.size(); i++)
  {
    if(k){
      jumlah += ans[i].second - ans[i].first;
      k--;
    }else{
      jumlah += ans[i].second;
    }
  }
  cout << jumlah << endl;
}