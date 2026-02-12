#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  ll n, ax, ay, bx, by;
  cin >> n >> ax >> ay >> bx >> by;

  map<int,vector<ll>> mp;
  mp[ax].push_back(ay);
  mp[bx].push_back(by);
  vector<ll> xx(n);
  vector<ll> yy(n);

  for (int i = 0; i < n; i++)
  {
    cin >> xx[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> yy[i];
  }
  
  for (int i = 0; i < n; i++)
  {
    mp[xx[i]].push_back(yy[i]);
  }
  
  
  map<ll, pair<ll,ll>> cache;
  for(auto [a, b] : mp){
    ll mn = INT_MAX;
    ll mx = 0;
    for(auto y : b){
      mn = min(y, mn);
      mx = max(y, mx);
    }
    cache[a] = {mn, mx};
  }
  int m = (int)mp.size();
  
  vector<vector<ll>> dp(mp.size(), vector<ll>(2, 0));
  dp[0][0] = 0; 
  dp[0][1] = 0;

  int temp1 = 0;
  int temp2 = 0;
  int i = 0;
  for(auto [a, z] : cache){
    auto [mn, mx] = z;
    ll temp = mx - mn;
    if(i > 0){
      ll prevlow = dp[i-1][0] + abs(temp1 - mx);
      ll prevhigh = dp[i-1][1] + abs(temp2 - mx);
      dp[i][0] = min(prevlow, prevhigh) + temp;

      prevlow = dp[i-1][0] + abs(temp1 - mn);
      prevhigh = dp[i-1][1] + abs(temp2 - mn);
      dp[i][1] = min(prevlow, prevhigh) + temp;
    }
    temp1 = mn;
    temp2 = mx;
    i++;
  }

  cout << dp[m-1][0] + abs(bx - ax) << endl;
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