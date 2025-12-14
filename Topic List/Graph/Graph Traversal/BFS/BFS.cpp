/*

  Author  : Iham.
  Tag     : BFS

*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

void bfs(int x){
  queue<int> q;
  vis[x] = 1;
  q.push(x);
  cout << x << " ";
  while (!q.empty())
  {
    int v = q.front();
    q.pop();
    for(auto u : adj[v]){
      if(!vis[u]){
        q.push(u);
        vis[u] = 1;
        cout << u << " ";
      }
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
  
  vis.resize(n+1, 0);
  for (int i = 1; i <= n; i++)
  {
    if(!vis[i]){
      bfs(i);
      cout << endl;
    }
  }
  
}