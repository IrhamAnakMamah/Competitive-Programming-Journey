#include <bits/stdc++.h>
using namespace std;

int f(vector<vector<int>> &dp,int a[][3], int n, int last){
  if(n==0){
    int maxim = 0;
    for (int i = 0; i < 3; i++)
    {
      if(i!=last){
        maxim = max(maxim,a[0][i]);
      }
    }
    return maxim;
  }

  if(dp[n][last]!=0){
    return dp[n][last];
  }
  int maxim = 0;
  for (int i = 0; i < 3; i++)
  {
    if(i!=last){
      int point = a[n][i] + f(dp,a,n-1,i);
      maxim = max(maxim,point);
    }
  }
  dp[n][last] = maxim;
  return dp[n][last];
}

int main (){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int a[n][3];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        cin >> a[i][j];
      }
    }
    vector<vector<int>> dp(n+1,vector<int>(3,0));
    int ans = f(dp,a,n-1,NULL);
    cout << ans << "\n";
  }
}