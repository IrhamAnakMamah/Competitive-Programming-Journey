#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

vector<ll> dp;

ll f(ll x){
  if(x == 0) return 0;
  if(dp[x] != -1) return dp[x];

  ll res = INT_MAX;
  ll temp = x;

  while (temp > 0)
  {
    ll digit = temp % 10;
    temp /= 10;
    if(digit > 0){
      res = min(res, f(x - digit) + 1); 
    }
  }
  dp[x] = res;
  return res;
}

int main(){
  ll n = 167;
  cin >> n;

  dp.resize(n+1, -1);

  ll ans = f(n);

  cout << dp[n] << endl;
}