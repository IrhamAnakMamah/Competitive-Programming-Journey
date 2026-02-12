#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 2e5 + 5;

int a[MAXN];
int res = 0;
vector<set<int>> adj;
vector<vector<int>> adj2;
vector<int> vis; 
vector<bool> hapus; 

void dfs(int u, int w, int prev){
  vis[u] = 1;
  for(auto v : adj[u]){
    if(hapus[v] || vis[v]){
      continue;
    }
    if(w == -1){
      dfs(v, u, a[u]);
    }else{
      if(a[v] < 0){
        if(prev < 0){
          res -= prev;
          res -= a[v];
          hapus[v] = 1;
          hapus[w] = 1;
          for(auto x : adj[v]){
            adj[u].insert(x);
          }
          for(auto x : adj[w]){
            adj[x].insert(u);
          }
        }else{
          if(abs(a[v]) > prev){
          res -= prev;
          res -= a[v];
          hapus[v] = 1;
          hapus[w] = 1;
          for(auto x : adj[v]){
            adj[u].insert(x);
          }
          for(auto x : adj[w]){
            adj[x].insert(u);
          }
          }
        }
      }else{
        if(prev < 0){
          if(abs(prev) > a[v]){
          res -= prev;
          res -= a[v];
          hapus[v] = 1;
          hapus[w] = 1;
          for(auto x : adj[v]){
            adj[u].insert(x);
          }
          for(auto x : adj[w]){
            adj[x].insert(u);
          }
          }
        }else{
          if(abs(a[v]) > prev){
          res -= prev;
          res -= a[v];
          hapus[v] = 1;
          hapus[w] = 1;
          for(auto x : adj[v]){
            adj[u].insert(x);
          }
          for(auto x : adj[w]){
            adj[x].insert(u);
          }
          }
        }
      }
    }
  }
  vis[u] = 0;
}

void solve(){
  res = 0;
  adj.clear();
  adj2.clear();
  vis.clear();
  hapus.clear();

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    res += a[i];
  }
  
  adj.resize(n);
  adj2.resize(n);
  vis.resize(n, 0);
  hapus.resize(n, 0);
  for (int i = 0; i < n-1; i++)
  {
    int x, y;
    cin >> x >> y;
    x--, y--;

    adj[x].insert(y);
    adj2[y].push_back(x);
  }
  
  for (int i = 0; i < n; i++)
  {
    if(!hapus[i]){
      dfs(i, -1, 0);
    }
  }
  
  cout << res << endl;

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve();
  }
  
}