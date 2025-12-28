#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;

  ll a[n];
  ll b[n];
  ll c[n];

  ll sum = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
    sum+=b[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> c[i];
  }

  vector<ll> pref(n+1, 0);
  vector<ll> suf(n+1, 0);

  for (int i = 1; i <= n; i++)
  {
    pref[i] += pref[i-1] + (a[i-1] - b[i-1]);
  }
  
  for (int i = n-1; i >= 0; i--)
  {
    suf[i] += suf[i+1] + (c[i] - b[i]);
  }
  
  vector<ll> mx(n+1, -1e9);
  
  for (int i = n-2; i >= 0; i--)
  {
    mx[i+1] = max(suf[i+1], mx[i+2]);
  }

  ll ans = 0;
  for (int i = 0; i < n-2; i++)
  {
    ans = max(ans, sum + pref[i+1] + mx[i+2]);
  }
  cout << ans << endl;


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