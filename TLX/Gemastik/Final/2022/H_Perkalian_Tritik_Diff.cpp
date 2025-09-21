#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
const ll MOD = 998244353;

int main(){
  int n,q;
  cin >> n >> q;

  vector<ll> a(n+2, 0),b(n+2, 0),c(n+2, 0);

  vector<ll> pref1(n+2, 0),pref2(n+2, 0),pref3(n+2, 0);
  for (int i = 0; i < q; i++)
  {
    int l,r;
    ll x,y,z;
    cin >> l >> r >> x >> y >> z;
    l--;
    pref1[l] += x;
    pref1[r] -= x;
    pref2[l] += y;
    pref2[r] -= y;
    pref3[l] += z;
    pref3[r] -= z;
  }
  
  for (int i = 1; i <= n; i++)
  {
    a[i] = a[i-1] + pref1[i-1];
    b[i] = b[i-1] + pref2[i-1];
    c[i] = c[i-1] + pref3[i-1];
  }

  for (int i = 1; i <= n; i++)
  {
    a[i] = a[i] % MOD;
    b[i] = b[i] % MOD;
    c[i] = c[i] % MOD;
  }
  
  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    ll temp = (a[i] * b[i]) % MOD;
    temp = (temp * c[i]) % MOD;
    ans = (ans + temp) % MOD;
  }
  cout << ans << endl;
}