#include <bits/stdc++.h>
using namespace std;

int ans = 0;
vector<bool> vis;
vector<vector<int>> edges;

void dfs(int x){
  vis[x] = 1;
  ans++;
  for(auto a : edges[x]){
    if(!vis[a]){
      dfs(a);
    }
  }
}

int main(){
  int n;
  cin >> n;

  vis.resize(n+1, 0);
  edges.resize(n+1);
  
  vector<int> bil;

  for (int i = 1; i <= n; i++)
  {
    int x,y;
    cin >> x >> y;

    
    if(x == 0 && y == 0){
      bil.push_back(i);
    }else{
      edges[y].push_back(i);
      edges[x].push_back(i);
    }
  }
  
  for(auto x : bil){
    dfs(x);
  }
  cout << ans << endl;
}