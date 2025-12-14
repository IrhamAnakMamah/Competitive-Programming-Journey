#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MODN = 998244353;

ll binpow(ll a, ll b){
  a%=MODN;
  ll res = 1;
  while(b > 0){
    if(b&1){
      res = res * a % MODN;
    }
    a = a * a % MODN;
    b >>= 1;
  }
  return res;
}

int main(){
  ll n,m,q;
  cin >> n >> m >> q;

  for (int i = 0; i < q; i++)
  {
    ll a,b;
    cin >> a >> b;
  }
  cout << binpow(m,n-q) << endl;
  
  return 0;
}