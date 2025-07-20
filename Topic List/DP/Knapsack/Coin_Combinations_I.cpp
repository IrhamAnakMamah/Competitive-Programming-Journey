#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
const ll MOD = 1e9 + 7;

ll n,k;
ll a[101];

vector<ll> dp;

int main(){
  cin >> n >> k;
  dp.resize(k+1, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  dp[0] = 1;
  
  for (int sum = 1; sum <= k; sum++)
  {
    for (int i = 0; i < n; i++)
    {
      if(sum - a[i] >= 0){
        dp[sum] = (dp[sum] + dp[sum-a[i]]) % MOD;
      }
    }
    
  }
  
  cout << dp[k] << endl;
}