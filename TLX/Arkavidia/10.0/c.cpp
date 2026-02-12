#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2e5+5;
ll bit[MAXN];
const ll mod = 1000000007;
vector<ll> inv(MAXN);
ll inv2;

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

ll modinv(ll a){
  return binpow(a,mod-2,mod);
}

void update(ll k, ll res){
  for (; k < MAXN; k+=k&-k)
  {
    bit[k] = (bit[k] + res) % mod;
  }
  
}

ll query(ll s){
  ll sum = 0;
  for(; s > 0; s-=s&-s){
    sum = (sum + bit[s]) % mod;
  }
  return sum;
}

void precomp(){
  inv[0] = 1;
  inv2 = modinv(2);
  for (int i = 1; i < MAXN; i++)
  {
    inv[i] = (inv[i-1] * inv2) % mod;
  }
}

void solve(){
  precomp();
  int q;
  cin >> q;
  
  while (q--)
  {
    int x;
    cin >> x;
    if(x == 1){
      ll s;
      cin >> s;
      ll temp; 
      temp = (s > MAXN ? MAXN - 1 : s);
      ll res = query(temp);
      ll ans = (res * binpow(2,s,mod)) % mod;
      cout << ans << endl;
    }else{
      int k;
      cin >> k;
      ll tot = 0;
      for (int i = 0; i < k; i++)
      {
        ll a;
        cin >> a;
        tot = (tot + a) % mod;
      }
      ll res = (tot * inv[k]) % mod;
      update(k, res);
    }
  }
  
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
  
}