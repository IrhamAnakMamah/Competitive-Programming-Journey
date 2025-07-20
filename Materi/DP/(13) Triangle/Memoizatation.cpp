#include <bits/stdc++.h>
using namespace std;

int f(vector<vector<int>> &dp,vector<vector<int>> a, int n, int i, int j){
  if(i==n){
    return a[i][j];
  }
  
  if(dp[i][j]!=-1) return dp[i][j];

  int temp1 = a[i][j] + f(dp,a,n,i+1,j);
  int temp2 = a[i][j] + f(dp,a,n,i+1,j+1);

  return dp[i][j] = min(temp1,temp2);
}

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
    int ans = f(dp,a,n-1,0,0);
    cout << ans << "\n";
  }
  
}