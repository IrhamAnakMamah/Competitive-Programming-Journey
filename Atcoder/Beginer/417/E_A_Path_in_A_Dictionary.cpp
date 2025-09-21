#include <bits/stdc++.h>
using namespace std;

int n,q,x,y;
bool ok = 0;

vector<bool> visited;
vector<int> ans;

void dfs(int v,vector<vector<int>> adj) {
  if(v == y){
    ok = 1;
    ans.push_back(v);
  }else{
    visited[v] = true;
    for (int u : adj[v]) {
      if (!visited[u]){
        dfs(u,adj);
      }
      if(ok){
        ans.push_back(v);
        break;
      }
    }
  }
}

int main(){
  int t;
  cin >> t;

  while (t--)
  {
    ans.clear();
    ok = 0;
    cin >> n >> q >> x >> y;
    visited.clear();
    visited.resize(n+1, 0);
    
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < q; i++)
    {
      int a,b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
      sort(adj[i].begin(), adj[i].end());
    }
    
    dfs(x,adj);
    reverse(ans.begin(), ans.end());
    for(auto a : ans){
      cout << a << " ";
    }
    cout << endl;
  }
  
}