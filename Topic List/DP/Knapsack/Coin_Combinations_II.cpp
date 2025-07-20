#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
const int MODN = 1e9+7;

ll a[101];
vector<ll> dp;

int main(){
  int n,x;
  cin >> n >> x;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  dp.resize(x+1, 0);
  dp[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int sum = 0; sum <= x; sum++)
    {
      if(a[i-1] <= sum){
        dp[sum] += dp[sum-a[i-1]];
        dp[sum] %= MODN;
      }
    }
    
  }
  
  cout << dp[x] << endl;
    
}