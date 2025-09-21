#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  int n,q;
  cin >> n >> q;

  vector<pair<ll,int>> a(n+1);
  for (int i = 1; i <= n; i++)
  {
    int x;
    cin >> x;
    a[i] = {x,i};
  }
  
  sort(a.begin(), a.end());
  vector<vector<int>> edges(n+2);
  for (int i = 0; i < q; i++)
  {
    int x,y;
    cin >> x >> y;
    edges[x].push_back(y);
  }
  
  vector<bool> vis(n+2, 0);
  auto bfs = [&] (int xx){
    queue<int> q;
    q.push(xx);
    vis[xx] = 1;
    ll sum = 1;
    while (!q.empty())
    {
      int x = q.front();
      q.pop();
      for(auto y : edges[x]){
        if(!vis[y]){
          q.push(y);
          vis[y] = 1;
          sum++;
        }
      }
    }
    return sum;
  };

  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    auto[x,y] = a[i];
    if(!vis[y]){
      ll sum = bfs(y);
      ans += sum * x;
    }
  }
  cout << ans << endl;
}