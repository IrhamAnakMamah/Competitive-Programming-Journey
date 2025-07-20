#include <bits/stdc++.h>
using namespace std;

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
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if(i==0 && j==0) dp[0][0] = a[0][0];
      else{
        int down = a[i][j];
        if(i>0){
          down+=dp[i-1][j];
        }else down = 1e9;
        int right = a[i][j];
        if(j>0){
          right +=dp[i][j-1];
        }else right = 1e9;

        dp[i][j] = min(right,down);
      }
    }
  }
  cout << dp[n-1][m-1] << "\n";
}