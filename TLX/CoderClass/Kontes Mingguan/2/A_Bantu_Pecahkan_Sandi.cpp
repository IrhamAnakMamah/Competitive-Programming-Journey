#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll n,m;
  cin >> n >> m;

  ll a[n];
  ll b[n];

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i] %= m;
  }

  ll sum = 0;
  ll count = 0;
  map<ll,ll> mp;
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
    mp[a[i]] += b[i];
    sum += b[i] * a[i];
    count += b[i];
  }
  
  ll ans = sum;
  ll k = 0;
  for(auto [x,y] : mp){
    sum -= count * (x - k + 1);
    sum += y * m;
    ans = max(ans, sum);
    k = x + 1;
  }
  cout << ans << endl;
}