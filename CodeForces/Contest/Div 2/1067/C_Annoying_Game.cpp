#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,k;
    cin >> n >> k;
    ll a[n];
    ll b[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
      cin >> b[i];
    }
    
    // kalo k ganjil, salah satu elemen ditambah
    if(k&1){
      vector<ll> pref(n);
      vector<ll> suf(n);
      pref[0] = a[0];
      for (int i = 1; i < n; i++)
      {
        pref[i] = max(pref[i-1] + a[i], a[i]);
      }

      suf[n-1] = a[n-1];
      for (int i = n-2; i >= 0; i--)
      {
        suf[i] = max(suf[i+1] + a[i], a[i]);
      }

      ll mx = -1e18;
      for (int i = 0; i < n; i++)
      {
        mx = max(mx, pref[i]);
      }
      
      for(int i = 0; i < n; i++) {
        ll res = pref[i] + suf[i] - a[i] + abs(b[i]);
        mx = max(mx, res);
      }
      cout << mx << endl;
    }else{
      ll sum = 0;
      ll mx = -1e18;
      for (int i = 0; i < n; i++)
      {
        sum = max(a[i], sum + a[i]);
        mx = max(sum, mx);
      }
      cout << max(sum, mx) << endl;
    }
  }
  
}