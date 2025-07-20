#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

ll n,k;
ll a[101][2];

ll f(int i, ll berat, vector<ll>& dp){
  if(i==n){
    return 0;
  }

  if(dp[i]!=-1){
    return dp[i];
  }

  ll take = 0;
  if(berat + a[i][0] <= k){
    take = a[i][1] + f(i+1,berat+a[i][0],dp);
  }
  ll nottake = f(i+1,berat,dp);
  return max(take,nottake);
}


int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i][0] >> a[i][1];
    }
    vector<ll>dp(n+1,-1);
    ll ans = f(0,0,dp);
    cout << ans << endl;
  }
  
}