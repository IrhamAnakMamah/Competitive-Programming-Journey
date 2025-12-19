#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MODN = 1e9+7;
const int MAXN = 1e6 + 5;

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

ll fac[MAXN + 1];
ll invfac[MAXN + 1];

void precomp(){
  fac[0] = 1;
  fac[1] = 1;
  for (int i = 2; i <= MAXN; i++)
  {
    fac[i] = (fac[i-1] * i) % MODN;
  }

  invfac[MAXN] = binpow(fac[MAXN], MODN - 2, MODN) % MODN;
  for (int i = MAXN - 1; i >= 0; i--)
  {
    invfac[i] = (invfac[i+1] * (i+1)) % MODN;
  }
  
}

int main(){
  precomp();
  ll a,b,n;
  cin >> a >> b >> n;
  
  char c = a + '0';
  char d = b + '0';
  vector<pair<ll,ll>> v;
  ll i = 0;
  ll j = n;
  while (j >= 0)
  {
    ll temp = (i * a) + (j * b);
    string s = to_string(temp);
    bool ok = 1;
    ll cnt1 = 0;
    ll cnt2 = 0;
    for (int i = 0; i < s.length(); i++)
    {
      if(s[i] == c || s[i] == d){
        continue;
      }else{
        ok = 0;
        break;
      }
    }
    if(ok){
      cnt1 = i;
      cnt2 = j;
      v.push_back({cnt1, cnt2});
    }
    i++;
    j--;
  }
  
  if(v.size() == 0){
    cout << 0 << endl;
    return 0;
  }

  ll sum = 0;
  for(auto [x,y] : v){
    ll temp = fac[n];
    temp = (temp * invfac[x]) % MODN;
    temp = (temp * invfac[y]) % MODN;
    sum = (sum + temp) % MODN;
  }
  cout << sum << endl;
}