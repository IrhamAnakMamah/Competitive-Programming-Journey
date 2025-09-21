#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  int n;
  cin >> n;

  ll a[n];
  ll mx = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    mx+=a[i];
  }
  
  vector<ll> pref(n+1, 0);
  for (int i = 1; i <= n; i++)
  {
    pref[i] = pref[i-1] + a[i-1];
  }
  
  mx = max(mx,pref[n] - pref[1]);
  for (int i = 1; i < n; i++)
  {
    mx = max(mx, ((pref[i] - pref[0]) * a[i]) + (pref[n] - pref[i+1]));
  }
  cout << mx << endl;
}