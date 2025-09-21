#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
vector<vector<int>> adj;
vector<int> vis;

bool ok = 0;

bool dfs(int i){
  vis[i] = 1;
  for(auto x : adj[i]){
    if(!vis[x]){
      if(dfs(x)){
        return true;
      }
    }else if(vis[x] == 1){
      return true;
    }
  }
  vis[i] = 2;
  ans.push_back(i);
  return false;
}

int main(){
  int n, m;
  cin >> n >> m;
  adj.resize(n+1);
  vis.resize(n+1, 0);
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
  }
  
  for (int i = 1; i <= n; i++)
  {
    if(!vis[i]){
      ok = dfs(i);
      if(ok){
        break;
      }
    }
  }
  if(ok){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  reverse(ans.begin(), ans.end());
  for(auto x : ans){
    cout << x << " ";
  }
  cout << endl;
}