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
  vector<int> p(n+1, -1);
  vector<int> ans;
  bool ada = 0;
  int index = 0;
  
  auto bfs = [&] (int k){
    index = k;
    queue<int> q;
    q.push(k);
    vis[k] = 1;
    int count = 0;
    p[k] = -1;
    while (!q.empty())
    {
      int a = q.front();
      q.pop();
      for(auto x : adj[a]){
        if(!vis[x]){
          vis[x] = 1;
          q.push(x);
          p[x] = a;
        }
      }
      count++;
    }
    if(count>=3){
      int j = 0;
      for (int i = k; i != -1; i = p[i])
      {
        if(j==2){
          break;
        }
        if(i == k){
          j++;
        }
        cout << i << " " << p[i] << endl;
        ans.push_back(i);
      }
      
    }
  };

  for (int i = 0; i < n; i++)
  {
    if(!ada){
      bfs(i);
    }
    if(ans.size() >= 3){
      ada = 1;
    }
  }
  

  if(ans.size()>=3){
    cout << ans.size() << endl;
    for(auto a : ans){
      cout << a << " ";
    }
    cout << endl;
  }else{
    cout << "IMPOSSIBLE" << endl;
  }
  
}