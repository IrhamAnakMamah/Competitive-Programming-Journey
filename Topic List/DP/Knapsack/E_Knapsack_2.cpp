#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int n;
ll k;
ll a[101], b[101];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
    }

    

    map<ll, ll> dp;

    for (int i = 0; i < n; ++i) {
      map<ll, ll> cur = dp;
      for (auto [uang, val] : cur) {
        if (uang + a[i] <= k) {
          dp[uang + a[i]] = max(dp[uang + a[i]], val + b[i]);
        }
      }
    }

    ll ans = 0;
    for (auto& [uang, val] : dp) {
      ans = max(ans, val);
    }

    cout << ans << endl;
    return 0;
}
