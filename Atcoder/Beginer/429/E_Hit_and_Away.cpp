#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;

  vector<vector<int>> adj(n+1);
  for (int i = 0; i < m; i++)
  {
    int u,v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  string s;
  cin >> s;
  
  auto bfs = [&] (int xx){
    vector<int> p(n+1, 0);
    vector<int> ans;
    queue<int> q;
    vector<bool> vis(n+1, 0);
    q.push(xx);

    while (!q.empty())
    {
      int u = q.front();
      vis[u] = 1;
      q.pop();
      for(auto v : adj[u]){
        if(!vis[v]){
          if(s[v] == 'S'){
            ans.push_back(v);
          }
          q.push(v);
          p[v] += p[u] + 1;
          if((int)ans.size() >= 2){
            break;
          }
        }
      }
      if((int)ans.size() >= 2){
        break;
      }
    }
    
    int sum = 0;
    for(auto x : ans){
      sum += p[x];
    }
    return sum;
  };
  
  for (int i = 0; i < n; i++)
  {
    if(s[i] == 'D'){
      cout << bfs(i) << endl;
    }
  }
  
}