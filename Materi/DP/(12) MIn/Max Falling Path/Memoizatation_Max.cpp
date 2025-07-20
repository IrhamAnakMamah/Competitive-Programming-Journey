//author irham

#include <bits/stdc++.h>
using namespace std;

int f(vector<vector<int>> &dp, vector<vector<int>> a,int n,int m, int i, int j){
  if(i == n && (j>=0 && j<=m)) return a[i][j];
  if(j<0 || j>m) return 0;
  if(dp[i][j]!=-1) return dp[i][j];

  int temp1, temp2, temp3;
  
  temp1 =a[i][j] + f(dp,a,n,m,i+1,j-1);//bawah kiri
  temp2 =a[i][j] + f(dp,a,n,m,i+1,j+1);//bawah kanan
  temp3 =a[i][j] + f(dp,a,n,m,i+1,j);//bawah

  return dp[i][j] = max(temp1, max(temp2,temp3));
}

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
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      ans = max(ans,f(dp,a,n-1,m-1,0,i));
    }
    cout << ans << "\n";
  }
}