#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>> adj(n+1);

  for (int i = 0; i < m; i++)
  {
    int x,y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<bool> visited(n+1,0);
  queue<int> q;
  int d[n+1];
  int p[n+1];
  auto bfs = [&](int u){
    visited[u] = 1;
    q.push(u);
    p[u] = -1;
    while(!q.empty()){
      int v = q.front();
      q.pop();
      for(int x : adj[v]){
        if(!visited[x]){
          visited[x] = 1;
          q.push(x);
          d[x] = d[v]+1;
          p[x] = v;
        }
      }
    }
  };

  bfs(1);

  if(!visited[n]){
    cout << "IMPOSSIBLE" << endl;
  }else{
    vector<int> ans;
    for (int i = n; i != -1; i = p[i])
    {
      ans.push_back(i);
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int z : ans){
      cout << z << " ";
    }
    cout << endl;
  }
}