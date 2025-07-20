#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

bool op(const pair<ll,ll> &a, const pair<ll,ll> &b){
  return a.first * a.second < b.first * b.second;
}

int main(){
  int n,q,k;
  cin >> n >> q >> k;
  ll a[n+1];
  ll minim = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i+1];
    minim = min(minim,a[i+1]);
  }
  
  vector<vector<ll>> adj(n+2);
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
  sort(cache.begin(), cache.end(), op);
  ll jumlah = 0;
  for (int i = 0; i < cache.size(); i++)
  {
    if(i < ((int)cache.size() - k)){
      jumlah += cache[i].first * cache[i].second;
    }else{
      jumlah += cache[i].second * minim;
    }
  }
  cout << jumlah << endl;
}