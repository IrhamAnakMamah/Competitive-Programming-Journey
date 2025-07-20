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

  vector<bool> vis(n+1, 0);

  auto bfs = [&] (int i){
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    while (!q.empty())
    {
      int x = q.front();
      q.pop();
      for(auto a : adj[x]){
        if(!vis[a]){
          vis[a] = 1;
          q.push(a);
        }
      }
    }
  };
  
  bool ada = 0;
  int bil = 0;
  vector<pair<int,int>> ans;
  for (int i = 1; i <= n; i++)
  {
    if(!vis[i] && !ada){
      ada = 1;
      bil = i;
      bfs(i);
    }else if(!vis[i] && ada){
      ans.push_back({bil,i});
      bil = i;
      bfs(i);
    }
  }
  
  cout << ans.size() << endl;
  for(auto [x,y] : ans){
    cout << x << " " << y << endl;
  }
}