#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll m = 1e9 + 7;
const int MAXN = 1e5 + 5;

ll fac[MAXN];
void precomp(){
  fac[0] = 1;
  for (int i = 1; i <= MAXN; i++) {
    fac[i] = fac[i - 1] * i % m;
  }
}

ll modpow(ll a, ll b) {
  ll r = 1;
  while (b) {
    if (b & 1) r = r * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return r;
}

ll inv(ll x) {
  return modpow(x, m-1);
}

ll Cmod(ll n, ll k) {
  if (k < 0 || k > n) return 0;
  return fac[n] * inv(fac[k]) % m * inv(fac[n-k]) % m;
}


int main(){
  precomp();
  int n;
  cin >> n;

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
  
  // C[n][k] = C[n - 1][k - 1] + C[n - 1][k]
  for (int i = 0; i < n; i++)
  {
    ll ans;
    ll x = a[i];
    ll y = b[i];
    if(x == y) ans = 0;
    else{
      ans = Cmod(x-1, y-1);
    }

    ll temp3 = Cmod(x,y-1);
    ans = ((ans % m) + (temp3 % m)) % m;
    cout << ans << endl;
  }
  
  
}