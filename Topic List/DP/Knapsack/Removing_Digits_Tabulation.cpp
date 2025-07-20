#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

vector<ll> dp;

int main(){
  ll n = 167;
  cin >> n;

  dp.resize(n+1, 1e9);

  dp[0] = 0;

  for (int i = 1; i <= n; i++)
  {
    int temp = i;
    while (temp > 0)
    {
      int digit = temp % 10;
      temp /= 10;
      if(digit > 0){
        dp[i] = min(dp[i], dp[i - digit] + 1);
      }
    }
      
  }
  

  cout << dp[n] << endl;
}