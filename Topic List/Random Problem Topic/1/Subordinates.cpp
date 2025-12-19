#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> d;
vector<int> vis;

int dfs(int u){
  vis[u] = 1;
  for(auto v : adj[u]){
    if(!vis[v]){
      d[u] += dfs(v);
    }
  }
  return d[u] + 1;
}

int main(){
  int n;
  cin >> n;

  adj.resize(n+1);
  d.resize(n+1, 0);
  vis.resize(n+1, 0);

  for (int i = 0; i < n-1; i++)
  {
    int a;
    cin >> a;
    adj[a].push_back(i+2);
  }
  
  dfs(1);
  for (int i = 1; i <= n; i++)
  {
    cout << d[i] << " ";
  }
  cout << endl;
}