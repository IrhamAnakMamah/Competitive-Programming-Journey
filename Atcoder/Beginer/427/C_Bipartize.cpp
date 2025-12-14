#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<bool> vis;
map<pair<int,int>, bool> vis_warna;
vector<int> warna;

int dfs(int i, int j){
  int hitung = 0;
  warna[i] = j;
  vis[i] = 1;
  for(auto a : edges[i]){
    if(!vis[a]){
      hitung += dfs(a,j^1);
    }else if(warna[a] == warna[i] && (vis_warna.find({a,i}) == vis_warna.end() && vis_warna.find({i,a}) == vis_warna.end())){
      vis_warna[{i,a}] = 1;
      hitung++;
    }
  }
  return hitung;
}

int main(){
  int n,m;
  cin >> n >> m;

  edges.resize(n+1);
  vis.resize(n+1);
  warna.resize(n+1, -1);

  for (int i = 0; i < m; i++)
  {
    int x,y;
    cin >> x >> y;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }
  
  int ans = INT_MAX;
  for (int i = 1; i <= n; i++)
  {
    vis.resize(n+1);
    vis.clear();
    vis_warna.clear();
    int cnt = dfs(i, 0);
    ans = min(cnt, ans);
  }
  cout << ans << endl;
}