#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int ok = 0;
bool berhenti = 0;
vector<int> ans;
vector<vector<int>> adj;
vector<int> vis;

void dfs(int u){
  vis[u] = 1;
  for(auto v : adj[u]){
    if(vis[v] == 1){
      ok = v;
      berhenti = 1;
      ans.push_back(v);
      break;
    }else if(vis[v] == 0){
      dfs(v);
      if(berhenti){
        if(ok > 0){
          ans.push_back(v);
          if(ok == v){
            ok = 0;
          }
        }
        break;
      }
    }
  }

  vis[u] = 2;
}

void solve(){
  int n, m;
  cin >> n >> m;

  adj.resize(n+1);
  vis.resize(n+1);
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
  }
  
  for (int i = 1; i <= n; i++)
  {
    if(vis[i] == 0){
      dfs(i);
      if(berhenti){
        if(ok > 0){
          ans.push_back(i);
        }
        break;
      }
    }
  }
  
  if(ans.size() == 0){
    cout << "IMPOSSIBLE" << endl;
  }else{
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for(auto x : ans){
      cout << x << " ";
    }
    cout << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}