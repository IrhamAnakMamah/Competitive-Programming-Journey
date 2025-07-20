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
  
  vector<ll> pref(n+1,0);
  for (int i = 1; i <= n; i++)
  {
    pref[i] = pref[i-1] + a[i-1];
  }
  
  ll ans = 0;
  for (int i = 0; i < n-1; i++)
  {
    ans += a[i] * (pref[n]-pref[i+1]);
  }
  cout << ans << endl;
}