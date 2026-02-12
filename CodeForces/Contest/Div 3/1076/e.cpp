#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;

  set<ll> s;
  vector<ll> vis(n+1, 0);
  queue<ll> q;
  for (int i = 0; i < n; i++)
  {
    ll a;
    cin >> a;
    if(!vis[a]){
      vis[a] = 1;
      q.push(a);
    }
    s.insert(a);
  }
  

  auto bfs = [&] (){
    while (!q.empty())
    {
      auto sum = q.front();
      q.pop();
      for(auto u : s){
        ll temp = sum * u;
        if(temp > n) break;
        if(!vis[temp]){
          vis[temp] = vis[sum] + 1;
          q.push(temp);
        }
      }
    }
    
  };

  bfs();

  for (int i = 1; i <= n; i++)
  {
    if(vis[i]){
      cout << vis[i] << " ";
    }else{
      cout << -1 << " ";
    }
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
    solve();
  }
  
  return 0;
}