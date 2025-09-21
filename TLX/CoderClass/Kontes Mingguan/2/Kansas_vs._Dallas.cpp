#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<int> sz, p, d;
vector<bool> vis;

void dfs(int x){
  sz[x] = 1;
  vis[x] = 1;
  for(auto a : edges[x]){
    if(!vis[a]){
      vis[a] = 1;
      d[a] = d[x] + 1;
      p[a] = x;
      dfs(a);
      sz[x] += sz[a];
    }
  }
}

int main(){
  int n,x,y;
  cin >> n >> x >> y;

  edges.resize(n);
  sz.resize(n+1, 0);
  vis.resize(n+1, 0);
  p.resize(n+1, 0);
  d.resize(n+1, 0);
  for (int i = 0; i < n-1; i++)
  {
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  x--;
  y--;
  dfs(x);

  int mid = (d[y]-1)/2;
  while(mid--){
    y = p[y];
  }

  if(2*sz[y] < n){
    cout << "Kansas" << endl;
  }else if(2 * sz[y] == n){
    cout << "Mabar" << endl;
  }else{
    cout << "Dallas" << endl;
  }
}