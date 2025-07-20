#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    ll n,q;
    cin >> n >> q;
    ll a[n];
    vector<ll> pref(n+1,0);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
      pref[i] = pref[i-1] + a[i-1];
    }
    
    for (int i = 0; i < q; i++)
    {
      int l,r;
      cin >> l >> r;
      cout << pref[r] - pref[l-1] << endl;
    }
    
  }
  
}