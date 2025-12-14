/*

  Author  : Iham.
  Tag     : DFS Recursion

*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

void dfs(int u){
  vis[u] = 1;
  cout << u << " ";
  for(auto v : adj[u]){
    if(!vis[v]){
      dfs(v);
    }
  }
}

int main(){
  int n;
  cin >> n;

  int m;
  cin >> m;

  adj.resize(n+1);

  for (int i = 0; i < m; i++)
  {
    int x,y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  
  vis.resize(n+1);
  for (int i = 4; i <= n; i++)
  {
    if(!vis[i]){
      dfs(i);
      cout << endl;
    }
  }
  
}