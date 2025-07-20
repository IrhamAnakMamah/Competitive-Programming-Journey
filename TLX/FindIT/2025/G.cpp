#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  ll n;
  ll ans = 0LL;

  cin >> n;
  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  vector<ll>pref(n+1,0);
  for (int i = 1; i <= n; i++)
  {
    pref[i] = pref[i-1] + a[i];
  }
  
  for (int i = 1; i < n-1; i++)
  {
    ans = max(ans,(pref[i]-pref[0])*(pref[n]-pref[i]));
  }
  cout << ans << endl;
}