#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  ll n, x, y;
  cin >> n >> x >> y;
  vector<ll> a(n);
  
  ll tot = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    tot += (a[i] / x) * y;
  }

  ll ans = 0;

  for (int i = 0; i < n; i++)
  {
    ll res = (a[i] / x) * y;
    ll sum = a[i] + (tot - res);

    ans = max(ans, sum);
  }
  
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