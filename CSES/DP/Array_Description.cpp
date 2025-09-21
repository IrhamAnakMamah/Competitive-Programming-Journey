#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const ll MODN = 1e9+7;
const int MAXN = 1e5 + 5;

int main(){
  ll n,x;
  cin >> n >> x;

  vector<ll> a(n);
  vector<vector<ll>> dp(n+1, vector<ll>(x+1, 0));
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  if(a[0] == 0){
    for (int i = 0; i <= x; i++)
    {
      dp[0][i] = 1;
    }
  }else{
    dp[0][a[0]] = 1;
  }

  for (int i = 1; i < n; i++)
  {
    if(a[i] == 0){
      for (int j = 1; j <= x; j++)
      {
        dp[i][j] += dp[i-1][j];
        if(j - 1 > 0) dp[i][j] += dp[i-1][j-1];
        if(j + 1 <= x) dp[i][j] += dp[i-1][j+1];
        dp[i][j] %= MODN;
      }
    }else{
      int j = a[i];
      dp[i][j] += dp[i-1][j];
      if(j - 1 > 0) dp[i][j] += dp[i-1][j-1];
      if(j + 1 <= x) dp[i][j] += dp[i-1][j+1];
      dp[i][j] %= MODN;
    }
  }
  
  ll ans = 0;
  for (int i = 1; i <= x; i++)
  {
    ans += dp[n-1][i];
    ans %= MODN;
  }
  cout << ans << endl;
  
}