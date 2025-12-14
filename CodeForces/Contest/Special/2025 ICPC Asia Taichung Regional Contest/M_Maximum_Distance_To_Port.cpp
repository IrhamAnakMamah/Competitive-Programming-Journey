#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,k;
  cin >> n >> m >> k;

  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i]--;
  }
  
  vector<vector<int>> adj(n+1);
  vector<bool> vis(n+1, 0);
  vector<int> d(n+1, 0);
  vector<int> cost(k+1, 0);

  for (int i = 0; i < m; i++)
  {
    int x,y;
    cin >> x >> y;
    x--, y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  
  auto bfs = [&] (int xx){
    queue<int> q;
    q.push(xx);
    vis[xx] = 1;
    while (!q.empty())
    {
      int v = q.front();
      q.pop();
      for(auto u : adj[v]){
        if(!vis[u]){
          vis[u] = 1;
          d[u] = d[v] + 1;
          if(cost[a[u]] < d[u]){
            cost[a[u]] = d[u];
          }
          q.push(u);
        }
      }
    }
    
  };

  bfs(0);
  for (int i = 0; i < k; i++)
  {
    cout << cost[i] << " ";
  }
  cout << endl;
  
}