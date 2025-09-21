#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<long long> cari(long long n) {
  vector<long long> a;
  for (long long d = 2; d * d <= n; d++) {
    while (n % d == 0) {
      a.push_back(d);
      n /= d;
    }
  }
  if (n > 1)
    a.push_back(n);
  return a;
}

long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

ll inv(ll x, ll m){
  return binpow(x, m-2, m);
}

int main(){
  const int MOD = 1e9 + 7;
  ll n;
  cin >> n;

  vector<ll> cek;
  cek = cari(n);  
  map<ll,ll> mp;

  for(auto x : cek){
    mp[x]++;
  }

  ll sz = cek.size();
  vector<ll> factorial(sz + 1, 1);
  factorial[0] = 1;
  for (ll i = 1; i <= sz; i++) {
    factorial[i] = factorial[i - 1] * i % MOD;
  }

  ll ans = factorial[sz];
  ll temp = 1;
  for(auto[x,y] : mp){
    temp*=factorial[y];
  }
  ans = (ans * inv(temp,MOD)) % MOD;
  cout << ans << endl;
}