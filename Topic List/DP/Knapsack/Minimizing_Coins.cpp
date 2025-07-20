#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
ll n,k;
ll a[101]; 

vector<ll> dp;

ll f(int jumlah){
  if(jumlah == 0) return 0;
  if(jumlah < 0) return INT_MAX;

  ll temp = INT_MAX;

  if(dp[jumlah] != -1){
    return dp[jumlah];
  }

  for (int i = 0; i < n; i++)
  {
    temp = min(temp, f(jumlah - a[i]) + 1);
  }
  dp[jumlah] = temp;
  return temp;
}

int main(){
  cin >> n >> k;
  dp.resize(k+1, -1);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  ll ans = f(k);
  cout << (ans>=INT_MAX ? -1 : ans) << endl;
}