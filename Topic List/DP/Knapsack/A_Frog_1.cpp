#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  vector<int> dp(n+1, 0);
  
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  for (int i = 1; i < n; i++)
  {
    dp[i] = abs(a[i] - a[i-1]) + dp[i-1];
    if(i > 1){
      dp[i] = min(abs(a[i] - a[i-2]) + dp[i-2], dp[i]);
    }
  }

  cout << dp[n-1] << endl;
}