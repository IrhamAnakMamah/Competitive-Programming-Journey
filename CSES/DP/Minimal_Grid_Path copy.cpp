#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  string s[n];
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }
  
  vector<vector<string>> dp(n+1, vector<string>(n+1, ""));

  /*
  
    string dp_prev[n]
    string dp_now[n]

  */

  // n+1 * n+1 * n+1
  // n^3
  // n^2

  /*
  
    n = 3
    0 0
    0 1 = 0 0
    0 2 = 0 1
    1 0
    1 1 = 1 0, 0 1
    1 2 = 
    2 0
    2 1
    2 2
  
  */

  dp[0][0] = s[0][0];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if(i > 0 && j > 0){
        // dp_now[i][j] = min(dp_now[i-1], dp_prev[j-1]);
        dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
        dp[i][j] += s[i][j];
      }else{
        if(i > 0){
          dp[i][j] = dp[i-1][j] + s[i][j];
        }else if(j > 0){
          dp[i][j] = dp[i][j-1] + s[i][j];
        }
      }

      // dp_now = dp_prev
    }
    
  }
  cout << dp[n-1][n-1] << endl;
}