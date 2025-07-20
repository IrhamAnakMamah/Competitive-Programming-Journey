#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
ll n,k;
ll a[101]; 

vector<ll> dp;

int main(){
  cin >> n >> k;
  dp.resize(k+1, INT_MAX);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  // ketika masih kosong (wajib)
  dp[0] = 0;

  for (int sum = 1; sum <= k; sum++)
  {
    for (int i = 0; i < n; i++)
    {
      if(sum - a[i] >= 0){
        dp[sum] = min(dp[sum], dp[sum - a[i]] + 1);
      }
    }
    
  }
  
  cout << (dp[k]>=INT_MAX ? -1 : dp[k]) << endl;
}