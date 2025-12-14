#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n,d,s;
map<ll,ll> mp;

ll f(ll sum){
  ll ans = sum;

  if(mp.find(sum) != mp.end()){
    return mp[sum];
  }

  for (ll i = sum*2; abs(i - sum) <= d && i <= n; i+=sum)
  {
    if((i % sum == 0)){
      ans = max(ans, f(i));
    }
  }
  return mp[sum] = ans;
}

int main(){
  cin >> n >> d >> s;

  f(s);
  cout << mp[s] << endl;
}