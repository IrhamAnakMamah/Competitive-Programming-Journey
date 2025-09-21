#include <bits/stdc++.h>
using namespace std;

vector<bool> vis;
vector<vector<int>> adj;
vector<int> comp;

void dfs(int i){
  vis[i] = 1;
  comp.push_back(i);
  for(auto x : adj[i]){
    if(!vis[x]){
      dfs(x);
    }
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  vis.resize(n+1, 0);
  adj.resize(n+1);
  for (int i = 0; i < m; i++)
  {
    int x,y;
    cin >> x >> y;
    adj[x].push_back(y);
  }
  
  bool ok = 1;
  pair<int,int> ans;
  for (int i = 1; i <= n; i++)
  {
    comp.clear();
    dfs(i);
    if(comp.size() != n){
      ok = 0;
      sort(comp.begin(), comp.end());
      for (int k = 1; k <= n; k++)
      {
        if(comp.size() < k){
          ans = {i,k};
          break;
        }
      }
      
    }
    vis.clear();
    vis.resize(n+1, 0);
  }
  if(ok){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
    cout << ans.first << " " << ans.second << endl;
  }
}