#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  int n;
  cin >> n;

  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  map<ll,ll> mp;
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    ll x = i - a[i];
    if(mp.find(x) != mp.end()){
      cout << i << endl;
      ans += mp[x];
    }
    x = i + a[i];
    mp[x]++;
  }
  cout << ans << endl;
}