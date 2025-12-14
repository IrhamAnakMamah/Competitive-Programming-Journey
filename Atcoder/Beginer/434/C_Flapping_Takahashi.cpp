#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    ll n,h;
    cin >> n >> h;

    ll mx = h;
    ll mn = h;
    ll cur = 0;

    bool ok = 1;
    for (int i = 0; i < n; i++)
    {
      ll t, l, r;
      cin >> t >> l >> r;
      if(!ok) continue;

      ll temp = t - cur;
      
      mn -= temp;
      mx += temp;

      mn = max(mn, l);
      mx = min(mx, r);

      if(mn > mx) ok = 0;
      cur = t;
    }
    cout << (ok ? "Yes" : "No") << endl;
    
  }
    
}