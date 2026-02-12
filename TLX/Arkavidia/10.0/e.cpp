#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;
  int sz = (int)s.length();
  vector<int> cache;
  int cnt = 0;
  for (int i = 0; i < sz; i++)
  {
    cnt += (s[i] == '0' ? 1 : -1);
    // cout << cnt << endl;
    cache.push_back(cnt);
  }
  
  int d = cnt;
  if(d == 0){
    ll ans = 0;
    for(auto a : cache){
      ans += (a != 0 ? 1 : 0);
    }
    cout << ans * k << endl;
    return;
  }

  if(d < 0){
    d = -d;
    vector<int> temp;
    for(auto a : cache){
      temp.push_back(-a);
    }
    cache = temp;
  }
  
  sort(cache.begin(), cache.end());
  ll ans = 0;
  for (int i = 1; i <= k; i++)
  {
    ll t = i * d;
    if(t > cache.back()) break;
    auto it = upper_bound(cache.begin(), cache.end(), t);
    // cout << it - cache.begin() << endl;
    ll dist = distance(it, cache.end());
    // cout << dist << endl;
    ans += dist;
  }
  
  // cout << endl;

  for (int i = 0; i < k; i++)
  {
    ll t = (-i) * d;
    if(t < cache.front()) break;
    auto it = lower_bound(cache.begin(), cache.end(), t);
    // cout << it - cache.begin() << endl;
    ll dist = distance(cache.begin(), it);
    // cout << dist << endl;
    ans += dist;
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
  
}