#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    ll n,q;
    cin >> n >> q;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<ll> pref(n+1,0);
    for (int i = 1; i <= n; i++)
    {
      pref[i] = pref[i-1] + a[i-1];
    }
    for (int i = 0; i < q; i++)
    {
      ll l,r, ans = 0;
      cin >> l >> r;

      ll kiri = lower_bound(a.begin(), a.end(), l) - a.begin();
      ll kanan = upper_bound(a.begin(), a.end(), r) - a.begin();
      ans = (kiri * l) - pref[kiri] + (pref[n] - pref[kanan]) - ((n - kanan) * r);
      // cout << kiri << " " << kanan << endl;
      cout << ans << endl; 
    }
    
  }
  
}