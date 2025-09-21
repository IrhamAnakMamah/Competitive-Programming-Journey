#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll n;
  cin >> n;

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
    pref = ((a[i] + pref)%n+n)%n;
    ans += mp[pref];
    mp[pref]++;
  }
  cout << ans << endl;
}