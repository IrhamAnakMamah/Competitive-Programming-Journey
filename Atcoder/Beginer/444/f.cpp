#include <bits/stdc++.h>
using namespace std;

using ll = long long;
map<ll,ll> dp;

ll f(ll sz, ll target){
  if(sz < target){
    return 0;
  }else if(sz < target * 2){
    return 1;
  }

  if(dp.count(sz)){
    return dp[sz];
  }

  return dp[sz] = f(sz/2, target) + f((sz + 1)/2, target);
}

void solve(){
  ll n, m;
  cin >> n >> m;

  vector<ll> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  sort(a.begin(), a.end(), greater<>());
  ll tongkat = (n + m + 1)/2;

  auto cek = [&] (ll target){
    if(target == 0) return true;

    ll res = 0;
    ll sum = 0;
    dp.clear();

    for (int i = 0; i < n; i++)
    {
      if(a[i] < target) break;
      ll temp = f(a[i], target);
      if(temp > 0){
        sum++;
        res+=(temp - 1);
      }
    }
    return (sum + min(res, m)) >= tongkat;
  };

  ll ans = -1;
  ll l = 0;
  ll r = 1e9;
  while (l <= r) 
  {
    ll mid = l + (r - l) / 2;
    if (cek(mid)) {
      ans = mid;
      l = mid + 1;
    }else{
      r = mid - 1;
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
  
}