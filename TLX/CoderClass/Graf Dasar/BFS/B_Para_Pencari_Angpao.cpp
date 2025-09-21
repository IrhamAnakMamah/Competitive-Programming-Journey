#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,k;
  cin >> n >> m >> k;

  
  vector<vector<int>> edges(n+1);
  for (int i = 0; i < m; i++)
  {
    int x,y;
    cin >> x >> y;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }
  
  
  vector<bool> kerabat(n+1, 1);

  for (int i = 0; i < k; i++)
  {
    int x;
    cin >> x;
    kerabat[x] = 0;
  }
  
  bool ok = 0;
  int last = 0;
  int count = 0;
  int ans = 0;
  auto bfs = [&](int xx){
    vector<bool> vis(n+1, 0);
    vector<int> d(n+1);
    vector<int> dist(n+1, -1);
    dist[xx] = 0;
    queue<int> q;
    q.push(xx);
    vis[xx] = 1;
    while (!q.empty())
    {
      int x = q.front();
      q.pop();
      for(auto a : edges[x]){
        if(!vis[a]){
          vis[a] = 1;
          q.push(a);
          if(!ok){
            if(!kerabat[a]){
              count++;
              kerabat[a] = 1;
            }
            if(count == k){
              last = a;
              count = -1; 
            }
          }
          d[a] = x;
          if(dist[a] != 0){
            dist[a] = dist[x] + 1;
          }
        }
      }
    }

    int sum = 0;
    cout << last << endl;
    for (int a = d[last]; a != d[a]; a = d[a])
    {
      cout << a << endl;
      sum++;
    }
    return sum;
    
  };

  ans += bfs(1);
  cout << ans << endl;
}