#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define matrix vector<vector<ll>>

const int MAXN = 1e6;
const int mod = 998244353;

matrix multiply(matrix a, matrix b) {
  matrix C(2, vector<ll>(2));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        C[i][j] = (C[i][j] + a[i][k] * b[k][j]) % mod;
      }
    }
  }
  return C;
}

matrix power(matrix a, ll p) {
  matrix res(2, vector<ll>(2));
  res[0][0] = 1;
  res[0][1] = 0;
  res[1][0] = 0;
  res[1][1] = 1;
    
  a[0][0] %= mod;
  a[0][1] %= mod;
  a[1][0] %= mod;
  a[1][1] %= mod;

  while (p > 0) {
    if (p & 1) res = multiply(res, a);
    a = multiply(a, a);
    p >>= 1;
  }
  return res;
}

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    ll l,r,k;
    cin >> l >> r >> k;
    matrix temp = {{1, 1}, {1, 0}};
    temp = power(temp, n);
    cout << ans << endl;
  }
  
}