#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll a;
  cin >> a;
  const int maxn = a+1;
  ll C[maxn + 1][maxn + 1];
  C[0][0] = 1;
  for (int n = 1; n <= maxn; ++n) {
    C[n][0] = C[n][n] = 1;
    for (int k = 1; k < n; ++k)
        C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
  }

  cout << C[a][5] + C[a][6] + C[a][7] << endl;
}