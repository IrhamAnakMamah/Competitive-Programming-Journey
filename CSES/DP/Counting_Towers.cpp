#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
const int MAXN = 1e6+1;
const ll MODN = 1e9+7;

vector<ll> dp(MAXN+2, 0);
vector<ll> a(MAXN+2, 0);
vector<ll> b(MAXN+2, 0);

void precomp(){
  a[1] = 1;
  b[1] = 1;
  dp[1] = 2;
  for (int i = 2; i <= MAXN; i++)
  {
    a[i] = (2*a[i-1] + b[i-1])%MODN;
    b[i] = (4*b[i-1] + a[i-1])%MODN;
    dp[i] = (a[i] + b[i])%MODN;
  }
  
}

int main(){
  precomp();
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    cout << dp[n] << endl;
  }
  
}