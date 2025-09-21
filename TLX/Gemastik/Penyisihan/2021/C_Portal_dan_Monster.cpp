#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;

  int a[n];
  vector<vector<int>> adj(n+1);
  vector<bool> vis (n+1, 0);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  for (int i = 0; i < q; i++)
  {
    int x,y;
    cin >> x >> y;
    x--, y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  
  auto bfs = [&] (int point){
    queue<int> q;
    q.push(point);
    vis[point] = 1;
    int sum = a[point];
    while (!q.empty())
    {
      int x = q.front();
      q.pop();
      for(auto y : adj[x]){
        if(!vis[y]){
          vis[y] = 1;
          sum += a[y];
          q.push(y);
        }
      }

    }
    
    return sum;
  };

  vector<int> cache;

  for (int i = 0; i < n; i++)
  {
    if(!vis[i]){
      cache.push_back(bfs(i));
    }
  }
  sort(cache.begin(), cache.end(), greater<>());

  int ans = 0;
  int j = 1;
  for(auto x : cache){
    ans += x * j;
    j++;
  }
  cout << ans << endl;
}