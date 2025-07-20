#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
const ll MOD = 1e9 + 7;

ll n,k;
ll a[101];

vector<ll> dp;

ll f(int jumlah){
  cout << "TES" << endl;
  if(jumlah == 0) return 1;

  if(dp[jumlah] != -1){
    return dp[jumlah];
  }
  
  ll sum = 0;

  for (int i = 0; i < n; i++)
  {
    if(jumlah >= a[i]){
      sum += f(jumlah - a[i]);
      sum %= MOD;
    }
  }
  dp[jumlah] = sum;
  return sum;
}

int main(){
  cin >> n >> k;
  dp.resize(k+1, -1);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  ll ans = f(k);
  cout << dp[k] << endl;
}