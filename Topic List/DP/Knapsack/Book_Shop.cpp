#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,x;
  cin >> n >> x;

  int a[n];
  int b[n];

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }
  
  vector<vector<int>> dp(1001, vector<int>(x+1, 0));
  for (int i = 1; i <= n; i++)
  {
    int harga = a[i-1];
    int lembar = b[i-1];
    for (int j = 1; j <= x; j++)
    {
      dp[i][j] = dp[i-1][j];
      if(harga <= j){
        dp[i][j] = max(dp[i][j], dp[i-1][j-harga] + lembar);
      }
    }
    
  }
  cout << dp[n][x] << endl;
}