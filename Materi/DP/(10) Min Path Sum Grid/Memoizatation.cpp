#include <bits/stdc++.h>
using namespace std;

int f(vector<vector<int>> &dp, vector<vector<int>> a,int i,int j){
  if(i==0 && j==0) return a[i][j];
  if(i<0 || j<0) return 1e9;
  if(dp[i][j]!=-1) return dp[i][j];

  int down = a[i][j] + f(dp,a,i,j-1);
  int right = a[i][j] + f(dp,a,i-1,j);
  dp[i][j] = min(down,right);

  return dp[i][j];
}

int main (){
  int n,m;
  cin >> n >> m;
  vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
  int ans = f(dp,a,n-1,m-1);
  cout << ans << "\n";
}