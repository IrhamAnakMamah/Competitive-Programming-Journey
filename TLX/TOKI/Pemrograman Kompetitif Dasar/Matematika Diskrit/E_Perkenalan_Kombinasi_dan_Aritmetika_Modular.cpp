#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main (){
  int n,a,b;
  cin >> n >> a >> b;
  int C[n+1][n+1];
  C[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
      C[i][0] = C[i][i] = 1;
      for (int k = 1; k < i; ++k){
          C[i][k] = ((C[i - 1][k - 1]%mod) + (C[i - 1][k]%mod))%mod;
      }
  }
  int ans = 0;
  for (int i = a; i <= b; i++)
  {
    ans = ((ans%mod)+(C[n][i]%mod))%mod;
  }
  cout << ans << "\n";

}