#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 998244353;
ll ans = 1;
vector<ll> cache(2e5+5, 0);
vector<ll> num(2e5+5, 0);
vector<ll> total(2e5+5, 0);

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

void calc(){
  for (int i = 1; i <= 2e5; i++)
  {
    ll cnt = 0;
    for (int j = i; j <= 2e5; j+=i)
    {
      cnt += cache[j];
    }
    num[i] = cnt;
  }

  for (int i = 1; i <= 2e5; i++)
  {
    total[i] = (num[i] * (num[i] - 1))/2;
  }

  for (int i = 2e5; i > 0; i--)
  {
    for (int j = 2 * i; j <= 2e5; j+=i)
    {
      total[i] -= total[j];
    }
  }
  
  for (int i = 1; i <= 2e5; i++)
  {
    if(total[i] > 0){
      ll temp = binpow(i, total[i], mod);
      ans = (ans * temp) % mod;
    }
  }
  
}

void solve(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    cache[a]++;
  }
  calc();
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;

  while (t--)
  {
    solve();
  }
  
  return 0;
}
