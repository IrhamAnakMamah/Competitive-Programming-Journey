#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const ll MOD = 1e5;

int n,k;
ll a[101];
ll b[101];
map<pair<ll,ll>,ll> dp;

ll f(int i, ll uang){
  if(i==-1){
    return 0;
  }

  auto it = dp.find({i,uang});
  if(it != dp.end()){
    return dp[{i,uang}];
  }

  ll nottake = f(i-1,uang);
  ll take = -1;
  if(uang>=a[i]){
    take = b[i] + f(i-1,uang-a[i]);
  }
  dp[{i,uang}] = max(nottake,take);
  return max(nottake,take);
}

int main(){
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i] >> b[i];
  }

  ll ans = f(n-1,k);
  cout << dp[{n-1,k}] << endl;
}