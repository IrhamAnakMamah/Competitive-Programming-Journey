#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  int a[n];
  vector<int> dp(n+1, 0);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  for (int i = 1; i < n; i++)
  {
    dp[i] = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
      if(i - j >= 0){
        dp[i] = min(abs(a[i] - a[i-j]) + dp[i - j], dp[i]);
      }
    }
    
  }

  cout << dp[n-1] << endl;
}