#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  int n,m;
  cin >> n >> m;

  ll a[n][m];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }
  
  vector<vector<ll>> dp(n+1, vector<ll>(m+1, -1e5));

  dp[0][0] = 0;
  

  for (int y = 1; y <= n; y++) {
    for (int x = 1; x <= n; x++) {
    sum[y][x] = max(sum[y][x-1],sum[y-1][x])+value[y][x];
  }
 }

}