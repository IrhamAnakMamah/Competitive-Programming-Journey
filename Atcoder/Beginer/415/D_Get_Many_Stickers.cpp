#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

bool op(const pair<ll,ll> &a, const pair<ll,ll> &b){
  return (a.second - a.first) > (b.second - b.first);
  // return a.second > b.second;
}

int main(){
  ll n,m;
  cin >> n >> m;

  vector<pair<ll,ll>> a(m);
  for (ll i = 0; i < m; i++)
  {
    ll x,y;
    cin >> x >> y;
    a[i] = {x,y};
  }

  sort(a.begin(), a.end(), op);

  ll bot = 0;
  ll kosong = n;
  ll ans = 0;

  ll j = 0;

  while (j<m)
  {
    auto[x,y] = a[j];
    if(kosong >= x){
      ll temp = kosong - x;
      ans += (temp / (x - y)) + 1;
      kosong = kosong - ((temp / (x - y)) + 1) * (x-y);
    }
    j++;
  }
  
  cout << ans << endl;
}