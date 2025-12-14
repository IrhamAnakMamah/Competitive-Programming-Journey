#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 5e4 + 5;

vector<pair<char,ll>> f1;
vector<pair<char,ll>> f2;

map<pair<int,ll>,ll> dp;
ll n;

ll calc(pair<char,ll> v, ll p){
  auto[x,y] = v;
  if(x == 'x'){
    return p * y;
  }else{
    return p + y;
  }
}

ll f(ll idx, ll p){
  if(idx == n-1){
    ll temp = 0;
    temp = max(calc(f1.back(), p), calc(f2.back(), p));
    return dp[{idx,p}] = temp;
  }

  if(dp.find({idx,p}) != dp.end()){
    return dp[{idx,p}];
  }

  ll ans1 = f(idx+1, calc(f1[idx], p));
  ll ans2 = f(idx+1, calc(f2[idx], p));

  return dp[{idx,p}] = max(ans1, ans2);
}

int main(){
  ll p;
  cin >> n >> p;

  for (ll i = 0; i < n; i++)
  {
    char c;
    ll x;
    cin >> c >> x;
    f1.push_back({c,x});
    cin >> c >> x;
    f2.push_back({c,x});
  }

  // for(auto [x,y] : f1){
  //   cout << x << " " << y << endl;
  // }
  // cout << endl;

  // for(auto [x,y] : f2){
  //   cout << x << " " << y << endl;
  // }
  // cout << endl;

  ll ans = f(0, p);
  cout << ans << endl;
}