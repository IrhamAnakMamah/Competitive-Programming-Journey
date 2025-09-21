#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

int main(){
  ll n,f;
  cin >> n >> f;

  vector<ll> dp(max(n+1, 4 * 1LL), 0);
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 2;
  for (int i = 4; i <= n; i++)
  {
    dp[i] = (dp[i-1] + dp[i-3] + 1) % MOD;
  }
  
  for (ll i = 1; i <= n; i++)
  {
    ll idx = min(i, n-i+1);
    // cout << idx << " ";
    if(f == 1LL){
      cout << (i == 1LL || i == n) << " ";
    }else{
      if(idx == 1){
        cout << dp[n] << " ";
      }else{
        cout << (dp[n - 2 * idx + 1] + dp[n - 2 * idx + 2])%MOD << " ";
      }
    }
  }
  cout << endl;
  
}
