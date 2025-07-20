#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while(t--){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> a[i][j];
      }
    }

    for(int i = 0; i<m; i++) dp[0][i] = a[0][i];

    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        int temp1 = a[i][j] + dp[i-1][j];

        int temp2 = a[i][j]; 
        if(j-1>=0) temp2 += dp[i-1][j-1];
        else temp2 += -1e8;

        int temp3 = a[i][j]; 
        if(j+1<m) temp3 += dp[i-1][j+1];
        else temp3 += -1e8;

        dp[i][j] = max(temp1,max(temp2,temp3));
      }
    }
    int ans = -1e8;
    for (int i = 0; i < m; i++)
    {
      ans = max(ans,dp[n-1][i]);
    }
    cout << ans << "\n";
  }
}