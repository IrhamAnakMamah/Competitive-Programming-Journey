#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

ll n,k;
vector<ll> a;
vector<ll> dp;

int f(int n){
  if(n <= 0){
    return (n == 0 ? a[n] : 0);
  }

  if(dp[n] != -1){
    return dp[n];
  }

  int pick = a[n] + f(n-k);
  int notpick = f(n-1);

  return dp[n] = max(pick,notpick);
}

int main(){
  cin >> n >> k;
  a.resize(n+1);
  dp.resize(n+1,-1);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  int ans = f(n-1);
  cout << ans << endl;
}