#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;

  vector<ll> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  auto calc = [&] (vector<ll> x){
    ll sum = 0;
    map<ll,ll> mp1, mp2;
    for (int i = 0; i < n; i++)
    {
      if(x[i] % 3 == 0){
        mp1[x[i] / 3]++;
      }
      if(x[i] % 7 == 0){
        mp2[x[i] / 7]++;
      }
      if(x[i] % 5 == 0){
        ll temp = x[i] / 5;
        sum += mp1[temp] * mp2[temp];
      }
    }
    return sum;
  };

  ll ans = calc(a);
  reverse(a.begin(), a.end());
  ans += calc(a);
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

