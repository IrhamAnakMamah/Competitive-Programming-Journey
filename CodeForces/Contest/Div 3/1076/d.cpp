#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;

  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  ll b[n];
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }
  
  sort(a, a+n);

  vector<ll> pref(n+1, 0);
  for (int i = 1; i <= n; i++)
  {
    pref[i] = pref[i-1] + b[i-1];
  }
  
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    ll temp = pref[i+1];
    if(temp > n){
      break;
    }

    ll sword = a[n - temp];
    ll sum = (sword) * (i+1);
    ans = max(sum, ans);
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
  
  return 0;
}