#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
  int n;
  cin >> n;

  ld a = 0;
  ld b = 0;
  ld ans = 0;
  for (int i = 0; i < n; i++)
  {
    ld x, y;
    cin >> x >> y;
    ans += sqrt(pow(a - x, 2) + pow(b - y, 2));
    a = x;
    b = y;
  }
  
  ans += sqrt(pow(a, 2) + pow(b, 2));
  cout << fixed << setprecision(20) << ans << endl;
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