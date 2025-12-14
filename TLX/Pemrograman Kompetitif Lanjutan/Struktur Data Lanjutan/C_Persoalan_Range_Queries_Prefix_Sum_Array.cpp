#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n;
  cin >> n;

  ll a[n];
  vector<ll> pref(n+1, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++)
  {
    pref[i] = pref[i-1] + a[i-1];
  }
  
  int q;
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    int l, r;
    cin >> l >> r;
    cout << pref[r] - pref[l-1] << endl;
  }
  
  
}