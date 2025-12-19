#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> adj;
vector<int> vis;
vector<int> cat;
int ans = 0;

void dfs(int u, int cnt){
  vis[u] = 1;

  if(cat[u] == 1){
    cnt++;
  }else{
    cnt = 0;
  }

  if(cnt > k){
    return;
  }

  bool ok = 0;
  for(auto v : adj[u]){
    if(!vis[v]){
      dfs(v, cnt);
      ok = 1;
    }
  }
  
  if(!ok){
    ans++;
  }
}

int main(){
  cin >> n >> k;

  adj.resize(n+1);
  vis.resize(n+1, 0);
  cat.resize(n+1, 0);
  for (int i = 1; i <= n; i++)
  {
    cin >> cat[i];
  }
  
  for (int i = 0; i < n-1; i++)
  {
    int x,y;
    cin >> x >> y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  dfs(1, 0);

  cout << ans << endl;
}