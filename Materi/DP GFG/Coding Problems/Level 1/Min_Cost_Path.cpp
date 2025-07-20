#include <bits/stdc++.h>
using namespace std;

int n,m;

int f(vector<vector<int>> &dp, vector<vector<int>> a,int i, int j){
  if(i==0 && j==0) return a[i][j];
  if(i<0 || j<0) return 1e9;

  if(dp[i][j]!=-1) return dp[i][j];

  int kanan = a[i][j] + f(dp,a,i-1,j);
  int bawah = a[i][j] + f(dp,a,i,j-1);
  int tengah = a[i][j] + f(dp,a,i-1,j-1);
  dp[i][j] = min(kanan,min(bawah,tengah));
  
  return dp[i][j];
}

int main (){
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }
  int ans = f(dp,a,n-1,m-1);
  cout << ans << "\n";
  return 0;
}