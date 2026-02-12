#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> adj;
vector<vector<ll>> dp;
ll ans = 0;
int n, k;

void dfs(int u, int p){
  dp[u][0] = 1;
  for(auto v : adj[u]){
    if(v == p) continue;

    dfs(v, u);

    for (int i = 0; i < k; i++)
    {
      int rem = k - i - 1;
      ans += (dp[v][i] * dp[u][rem]);
    }
    
    for (int i = 0; i < k; i++)
    {
      dp[u][i+1] += dp[v][i];
    }
    
  }
}

void solve(){
  cin >> n >> k;

  adj.resize(n+1);
  dp.resize(n+1, vector<ll>(k+1, 0));

  for (int i = 0; i < n-1; i++)
  {
    int x, y;
    cin >> x >> y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  
  dfs(1, 0);
  
  cout << ans << endl;
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