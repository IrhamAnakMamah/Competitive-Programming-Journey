#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
	freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);
  ll n,m;
  cin >> n >> m;

  vector<pair<ll,ll>> a(m);

  ll mn = 1e18;
  ll mx = 0;
  for (int i = 0; i < m; i++)
  {
    ll x,y;
    cin >> x >> y;
    mn = min(mn, x);
    mx = max(mx, y);
    a[i] = {x,y};
  }
  
  sort(a.begin(), a.end());

  ll l = 1;
  ll r = mx - mn;

  auto cek = [&] (ll x){
    ll point = a[0].first;
    ll count = 1;
    int j = 0;

    while (point + x <= a[m-1].second)
    {
      while (point + x > a[j].second)
      {
        j++;
      }
      point = max(a[j].first, point + x);
      count++;
    }
    
    return count >= n;
  };

  ll ans = 0;

  while (l<r)
  {
    ll mid = l+(r-l+1)/2;
    if(cek(mid)){
      l = mid;
    }else{
      r = mid-1;
    }
  }
  
  cout << r << endl;
}