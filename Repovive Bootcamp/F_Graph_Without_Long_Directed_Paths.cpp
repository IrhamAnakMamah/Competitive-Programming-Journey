#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis;
bool ok = 1;

void dfs(int u, int col){
  vis[u] = col;
  for(auto v : adj[u]){
    if(vis[v] == -1){
      dfs(v, col ^ 1);
    }else{
      if(vis[u] == vis[v]){
        ok = 0;
      }
    }
  }
}

int main(){
  int n,m;
  cin >> n >> m;

  adj.resize(n+1);
  vis.resize(n+1, -1);

  int x[m], y[m];
  for (int i = 0; i < m; i++)
  {
    cin >> x[i] >> y[i];
    adj[x[i]].push_back(y[i]);
    adj[y[i]].push_back(x[i]);
  }
  
  dfs(1,0);

  if(!ok){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
    for (int i = 0; i < m; i++)
    {
      cout << (vis[x[i]] < vis[y[i]]);
    }
    cout << endl;
  }
  
}