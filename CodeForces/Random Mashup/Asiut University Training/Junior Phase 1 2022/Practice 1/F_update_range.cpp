#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    int n,q;
    cin >> n >> q;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    vector<ll> pref(n+2,0);
    for (int i = 0; i < q; i++)
    {
      int l,r,z;
      cin >> l >> r >> z;
      pref[l] += z;
      pref[r+1] -=z;
    }

    for (int i = 1; i <= n; i++)
    {
      pref[i] += pref[i-1];
    }
    
    for (int i = 1; i <= n; i++)
    {
      pref[i] += a[i-1];
    }

    for (int i = 1; i <= n; i++)
    {
      cout << pref[i] << " ";
    }
    
  }
  
}