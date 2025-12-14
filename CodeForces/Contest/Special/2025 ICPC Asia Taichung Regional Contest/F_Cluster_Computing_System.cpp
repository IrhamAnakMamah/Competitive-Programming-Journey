#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n;
  cin >> n;

  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  ll pref[n];
  ll suf[n];

  pref[0] = a[0];
  suf[n-1] = a[n-1];

  for (int i = 1; i < n; i++)
  {
    pref[i] = __gcd(pref[i-1], a[i]);
  }
  
  for (int i = n-2; i >= 0; i--)
  {
    suf[i] = __gcd(suf[i+1], a[i]);
  }
  
  ll ans = 0;
  for (int i = 1; i < n; i++)
  {
    ans += min(pref[i], suf[i]);
  }
  cout << ans << endl;
  
}