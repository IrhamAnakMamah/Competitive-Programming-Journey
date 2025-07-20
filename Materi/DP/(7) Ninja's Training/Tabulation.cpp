#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    int a[n][3];
    for (int i = 0; i < n; i++){
      for (int j = 0; j < 3; j++){
        cin >> a[i][j];
      }
    }
    vector <vector<int >> dp(n+1,vector<int>(4,0));

    dp[0][0] = max(a[0][1],a[0][2]);
    dp[0][1] = max(a[0][2],a[0][0]);
    dp[0][2] = max(a[0][1],a[0][0]);
    dp[0][3] = max(a[0][1],max(a[0][0],a[0][2]));

    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        for (int k = 0; k < 3; k++)
        {
          if(k!=j){
            int point = a[i][k] + dp[i-1][k];
            dp[i][j] = max(point,dp[i][j]);
          }
        }
        
      }
      
    }
    cout << dp[n-1][3] << "\n";
  }
  
}