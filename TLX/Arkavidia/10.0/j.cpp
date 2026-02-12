#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2e6 + 5;
const ll MODN = 998244353;

ll fac[MAXN+1];
ll invfac[MAXN+1];

ll binpow(ll a, ll b, ll m) {
  a %= m;
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

void precomp(){
  fac[0] = 1;
  fac[1] = 1;
  for (int i = 2; i <= MAXN; i++)
  {
    fac[i] = (fac[i-1] * i) % MODN;
  }
  
  invfac[MAXN] = (binpow(fac[MAXN], MODN-2, MODN)) % MODN;
  for (int i = MAXN-1; i >= 0; i--)
  {
    invfac[i] = (invfac[i+1] * (i+1)) % MODN;
  }
  
}

ll C(ll n, ll r){
  if(n < 0 || r > n){
    return 0;
  }

  ll sum = fac[n];
  sum = (sum * invfac[r]) % MODN;
  sum = (sum * invfac[n-r]) % MODN;
  return sum;
}

void solve(){
  ll n, m, k;
  cin >> n >> m >> k;

  ll res1 = C(n + 2 * k, 2 * k + 1);
  ll res2 = binpow(m, n-1, MODN);
  ll res3 = (m * (m + 1))/2;
  ll ans = (res2 * res3) % MODN;
  // cout << res1 << " " << res2 << " " << res3 << endl;
  ans = (res1 * ans) % MODN;
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  precomp();
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve();
  }
  
}