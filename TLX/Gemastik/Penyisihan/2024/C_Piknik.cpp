#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;

  vector<vector<int>> adj(n+1);
  for (int i = 0; i < k; i++)
  {
    int x,y;
    cin >> x >> y;
    x--,y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  
  vector<bool> vis(n,0);
  int ans = 0;

  auto bfs = [&](int i){
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    int sum = 0;
    while (!q.empty())
    {
      int x = q.front();
      q.pop();
      sum++;
      for(auto a : adj[x]){
        if(!vis[a]){
          vis[a] = 1;
          q.push(a);
        }
      }
    }
    return sum;
  };

  int sendiri = 0;

  for (int i = 0; i < n; i++)
  {
    if(!vis[i]){
      int temp = bfs(i);
      if(temp == 1){
        sendiri++;
      }else{
        ans++;
      }
    }
  }
  
  if(sendiri > 1){
    ans++;
  }

  cout << ans << endl;

}