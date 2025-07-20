#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

ll n,x,y;
map<ll,ll> dp;

ll f(ll a){
  if(a == 0){
    return 0;
  }

  if(dp.count(a)){
    return dp[a];
  }

  ll ans = INT64_MAX;

  if(a >= 2){
    ans = min(ans, f(a/2) + (a%2) + x);
  }

  if(a >= 3){
    ans = min(ans, f(a/3) + (a%3) + y);
  }

  return dp[a] = min(ans,a);
}

int main(){
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++)
  {
    ll a;
    cin >> a;
    ll ans = f(a);
    cout << ans << endl;
  }
  
}