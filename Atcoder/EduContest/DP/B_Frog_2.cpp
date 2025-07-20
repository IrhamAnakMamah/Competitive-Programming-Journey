#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    int n,k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
       
    vector<int> dp(n+1,0);
    for (int i = 1; i < n; i++)
    {
      dp[i] = INT_MAX;
      for (int j = i-1; j >= max(0,i-k); j--)
      {
        dp[i] = min(dp[i], dp[j] + abs(a[i]-a[j]));
      }
      
      // if(i>1){
      //   dp[i] = min(dp[i], dp[i-2] + abs(a[i-2]-a[i]));
      // }
    }
    cout << dp[n-1] << endl;
  }
  
}