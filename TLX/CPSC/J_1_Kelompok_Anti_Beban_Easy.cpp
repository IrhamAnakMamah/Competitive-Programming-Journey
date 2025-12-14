#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e6;
const int mod = 998244353;

ll exp(ll x, ll n, ll m) {
	x %= m;
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

ll fib[MAXN];
void comp(){
  fib[1] = 1;
  fib[2] = 1;
  for (int i = 3; i < MAXN; i++)
  {
    fib[i] = ((fib[i-1] % mod) + (fib[i-2] % mod)) % mod;
  }
}

int main(){
  comp();
  int t;
  cin >> t;
  while (t--)
  {
    ll l,r,k;
    cin >> l >> r >> k;

    ll ans = 0;
    for (int i = l; i <= r; i++)
    {
      ll sum = fib[i+1];
      sum = ((sum % mod) * (exp(k, i, mod) % mod)) % mod;
      ans = ((ans % mod) + (sum % mod)) % mod;
    }
    cout << ans << endl;
  }
  
}