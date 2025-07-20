#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e7;
const int mod = 1e9 + 7;

ll fac[MAXN + 1];
ll inv[MAXN + 1];

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

void factorial() {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) { 
    fac[i] = fac[i - 1] * i % mod; 
  }
}

void inverses() {
	inv[MAXN] = exp(fac[MAXN], mod - 2, mod);
	for (int i = MAXN; i >= 1; i--) { 
    inv[i - 1] = inv[i] * i % mod; 
  }
}

ll c(ll n, ll r) { 
  return fac[n] * inv[r] % mod * inv[n - r] % mod; 
}

int main (){
	factorial();
	inverses();
  ll n,m;
  cin >> n >> m;
  ll a[n][m];
  ll b[n][m];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
    
  }

  for (int i = 0; i < n; i++)
  {
    b[i][0] = 0;
  }
  
  for (int i = 0; i < m; i++)
  {
    b[0][i] = 0;
  }
  
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < m; j++)
    {
      b[i][j] = ((a[i][j]%mod)+(b[i][j-1]%mod))%mod;
      ll temp = 0;
      temp = b[i-1][j] - b[i-1][j-1];
      b[i][j] = ((b[i][j]%mod)+(temp%mod))%mod;
    }
  }

  ll atas;

  cout << 1 << '\n';
  for (int i = 1; i < n; i++)
  {
    atas = 0;
    for (int j = 0; j < m; j++)
    {
      atas = ((atas%mod)+(b[i][j]%mod))%mod;
    }
    cout << c(atas/m, atas/(m*2)) << '\n';
  }
}