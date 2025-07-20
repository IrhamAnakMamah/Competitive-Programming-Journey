#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    vector<ll> dp(n+1,0);
    for (int i = 1; i < n; i++)
    {
      dp[i] = dp[i-1] + ((a[i]-a[i-1]) * (a[i]-a[i-1]));
      if(i>1){
        dp[i] = min(dp[i],dp[i-2] + (3*(a[i]-a[i-2])*(a[i]-a[i-2])));
      }
      dp[i-1] = min(dp[i-1],dp[i] + ((a[i]-a[i-1]) * (a[i]-a[i-1])));
    }
    
    cout << dp[n-1] << endl;
  }
  
}