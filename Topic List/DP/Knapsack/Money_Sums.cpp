#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
 
  int a[n];
  int sum = 1e5 + 1;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  vector<vector<bool>> dp(n+1, vector<bool>(1e5, 0));
  dp[0][0] = 1;
  /*
  
  n = 100
  sum = 1e5
  O() = 100 * 1e5 = 1e7
  
  */
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= sum; j++)
    {
      dp[i][j] = dp[i-1][j];
      int cur = j - a[i-1];
      if(cur >= 0 && dp[i-1][cur]){
        dp[i][j] = 1;
      }
    }
  }
 
  vector<int> ans;
  for (int i = 1; i <= sum; i++)
  {
    if(dp[n][i]){
      ans.push_back(i);
    }
  }
  
  cout << ans.size() << endl;
  for(auto xx : ans){
    cout << xx << " ";
  }
  cout << endl;
}