#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MODN = 1e9 + 7;

int main(){
  ll n;
  cin >> n;
  vector<ll> dp(n+1, 0);
  dp[0] = 1;
  dp[1] = 0;
  for (int i = 2; i <= n; i++)
  {
    dp[i] = ((i - 1) * ((dp[i-1] + dp[i-2]) % MODN)) % MODN;
  }
  cout << dp[n] << endl;
}