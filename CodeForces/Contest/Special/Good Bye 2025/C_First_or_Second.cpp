#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
using ll = long long;

int n;
ll a[MAXN];
// vector<vector<ll>> dp(2, vector<ll>(MAXN, -1));

// ll f(ll x, int i, int state){
//   if(i == n){
//     return 0;
//   }

//   ll sum = x + f(a[i], i + 1, 0);
//   sum = max(sum, f(x, i+1, 1) - a[i]);

//   return sum;
// }

void solve(){
  
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  // ans = f(a[0], 2, 1) - a[1];
  // cout << ans << endl << endl;
  // ans = max(ans, a[0] + f(a[1], 2, 0));

  // kasus elemen pertama ditambah
  vector<ll> suf(n+1, 0);
  for (int i = n-1; i >= 0; i--)
  {
    suf[i] = suf[i+1] + a[i];
  }
  
  ll ans = -1e9;
  ll l = 0;
  for (int i = 0; i < n; i++)
  {
    ll cur = l - suf[i+1];
    ans = max(ans, cur);
    if(i == 0){
      l += a[i];
    }else{
      l += abs(a[i]);
    }

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