#include <bits/stdc++.h>
using namespace std;

int f(vector<vector<int>> &dp,int i,int j){
  if(i==0 && j==0) return 1;
  if(i<0 || j<0) return 0;
  if(dp[i][j]!=0) return dp[i][j];

  dp[i][j] = f(dp,i-1,j) + f(dp,i,j-1);
  return dp[i][j];
}

int main (){
  int t;
  cin >> t;
  while (t--){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int ans = f(dp,n-1,m-1);
    cout << ans << "\n";
  }
}