#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    
    vector<int>dp(n+1,0);
    for (int i = 1; i < n; i++)
    {
      dp[i] = dp[i-1] + abs(a[i]-a[i-1]);
      if(i>1){
        dp[i] = min(dp[i],dp[i-2]+abs(a[i]-a[i-2]));
      }
    }
    cout << dp[n-1] << endl;
  }
  
}