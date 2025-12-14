#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n;
  cin >> n;

  ll ans = 0;
  for (ll i = 1; i <= n; i++)
  {
    ans += pow(2 * 1LL, i);
  }
  ll temp = (n >= 54 ? 2 : 0);
  cout << ans - temp << endl;
}