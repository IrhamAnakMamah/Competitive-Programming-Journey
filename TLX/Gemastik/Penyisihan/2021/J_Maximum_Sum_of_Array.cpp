#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

ll n,k;
vector<ll> a;
vector<ll> dp;

int main(){
  cin >> n >> k;
  a.resize(n+1);
  dp.resize(n+1,-1);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  ll mx = LLONG_MIN;
  dp[0] = a[0];
  for (int i = 1; i < n; i++)
  {
    dp[i] = max(dp[i-1], a[i]);
    if(i >= k){
      dp[i] = max(dp[i], dp[i-k] + a[i]);
    }
  }
  cout << dp[n-1] << endl;
}