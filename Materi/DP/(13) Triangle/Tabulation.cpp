#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n));
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j <= i; j++)
      {
        cin >> a[i][j];
      } 
    }

    for (int i = 0; i < n; i++)
    {
      dp[n-1][i] = a[n-1][i];
    }
    
    for (int i = n-2; i >= 0; i--)
    {
      for (int j = i; j >= 0; j--)
      {
        int temp1 = a[i][j] + dp[i+1][j];
        int temp2 = a[i][j] + dp[i+1][j+1];
        dp[i][j] = min(temp1,temp2);
      }
      
    }
    cout << dp[0][0] << "\n";
  }
  
}