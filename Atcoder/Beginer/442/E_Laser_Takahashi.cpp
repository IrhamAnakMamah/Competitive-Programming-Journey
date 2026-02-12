#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

bool comp(pair<int, ld> &a, pair<int, ld> &b) {
  return a.second < b.second;
}

void solve(){
  int n, q;
  cin >> n >> q;

  vector<pair<int,ld>> a(n);
  for (int i = 0; i < n; i++)
  {
    ld x, y;
    cin >> x >> y;
    a[i].first = i + 1;
    a[i].second = atan2(y, x);
  }
  
  sort(a.begin(), a.end(), comp);

  vector<int> counts;
  vector<int> mp(n + 1);
  
  if(n > 0){
    counts.push_back(1);
    mp[a[0].first] = 0;
  }

  int idx = 0;
  for (int i = 1; i < n; i++)
  {
    if(abs(a[i].second - a[i-1].second) < 1e-11){
      counts[idx]++;
    }else{
      idx++;
      counts.push_back(1);
    }
    mp[a[i].first] = idx;
  }

  int m = counts.size();
  vector<ll> pref(m + 1, 0);
  for (int i = 1; i <= m; i++)
  {
    pref[i] = pref[i-1] + counts[i-1];
  }

  while (q--)
  {
    int u, v;
    cin >> u >> v;
    
    int start_idx = mp[u];
    int end_idx = mp[v];
    
    ll ans = 0;
    if(start_idx >= end_idx){
      ans = pref[start_idx + 1] - pref[end_idx];
    }else{
      ans = (pref[start_idx + 1] - pref[0]) + (pref[m] - pref[end_idx]);
    }

    cout << ans << endl;
  }
  
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