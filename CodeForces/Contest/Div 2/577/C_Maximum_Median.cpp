#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

ll n,k;

int main(){
  cin >> n >> k;

  vector<ll> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  auto check = [&] (ll cek){
    ll total = 0;
    for (int i = (n-1)/2; i < n; i++)
    {
      total += max(1LL * 0,cek - a[i]);
    }
    return total <= k;
  };

  auto search = [&] (ll l, ll r){
    l--;
    while (l<r)
    {
      ll mid = l+(r-l+1)/2;
      if(check(mid)){
        l = mid;
      }else{
        r = mid-1;
      }
    }
    return l;
  };

  ll ans = search(2,2e9);
  cout << ans << endl;
}