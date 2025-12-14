#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<int> vis;

void dfs(int u){
  vis[u] = 1;
  for(auto v : edges[u]){
    if(!vis[v]){
      dfs(v);
    }
  }
}

int main(){
  int n,m;
  cin >> n >> m;

  edges.resize(n+1);
  vis.resize(n+1, 0);

  for (int i = 0; i < m; i++)
  {
    int x,y;
    cin >> x >> y;
    x--, y--;
    edges[y].push_back(x);
  }

  int q;
  cin >> q;
  while (q--)
  {
    int a,b;
    cin >> a >> b;
    b--;
    if(a == 1){
      if(!vis[b]){
        dfs(b);
      }
    }else{
      if(vis[b]){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }
  }
  
}