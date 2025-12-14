#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll n,m;
  cin >> n >> m;

  ll h[n+1],k[n+1],d[n+1];

  // harga, jumlah vitamin

  for (int i = 1; i <= n; i++)
  {
    cin >> h[i] >> k[i] >> d[i];
  }

  vector<ll> dp(m+1, 0);
  
  for (int i = 1; i <= n; i++)
  {
    if(d[i] == 1){//knapsack biasa
      for (ll x = m; x >= h[i]; x--)
      {
        dp[x] = max(dp[x], dp[x - h[i]] + k[i]);
      }
    }else{
      for (ll x = h[i]; x <= m; x++)
      {
        dp[x] = max(dp[x], dp[x - h[i]] + k[i]);
      }
    }
  }
  cout << dp[m] << endl;
}