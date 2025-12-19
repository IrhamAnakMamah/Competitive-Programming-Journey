#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll d[1001];
  d[0] = 1;
  d[1] = 0;
  for (int i = 2; i < 1001; i++)
  {
    d[i] = (i - 1) * (d[i-1] + d[i-2]);
  }

  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  for (int i = 0; i <= k; i++)
  {
    ll temp = 1;
    for (int j = 1; j <= i; j++)
    {
      temp = temp * (n - j + 1);
      temp /= j;
    }
    temp *= d[i];
    ans += temp;
  }
  cout << ans << endl;
}