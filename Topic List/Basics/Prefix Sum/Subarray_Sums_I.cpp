#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll n, x;
  cin >> n >> x;

  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  map<ll,int> mp;
  ll pref = 0;
  ll ans = 0;
  mp[0]++;
  for (int i = 0; i < n; i++)
  {
    pref += a[i];
    ans += mp[pref-x];
    mp[pref]++;
  }
  cout << ans << endl;
}