#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  ll n, m;
  cin >> n >> m;

  if (m == 0) {
    cout << 0 << endl;
    return;
  }

  ll x = sqrt(m);  
  ll r, c;
  if (x * x >= m) {
    r = x;
    c = x;
  } else if (x * (x + 1) >= m) {
    r = x;
    c = x + 1;
  } else {
    r = x + 1;
    c = x + 1;
  }

  ll ans = (r * n) + (c * n) - (r * c);  
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve();
  }
  
}