#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
using ll = long long;
const ll MODN = 1e9 + 7;
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

int main(){
  precomp();
  string s;
  cin >> s;

  ll sz = (ll)s.length();
  vector<ll> cnt(27, 0);
  for (int i = 0; i < sz; i++)
  {
    cnt[s[i]-'a']++;
  }
  
  ll ans = 1;
  for (int i = 0; i < 27; i++)
  {
    if(cnt[i] != 0){
      ans = (ans * invfac[cnt[i]]) % MODN;
    }
  }
  ans = (fac[sz] * ans) % MODN;
  cout << ans << endl;
}