#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
const int MODN = 1e9+7;

int main(){
  int n,m;
  cin >> n >> m;

  char c;
  bool cek[n][m];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> c;
      cek[i][j] = (c == '.');
    }
  }
  
  vector<vector<ll>> dp(1001,vector<ll>(1001, 0));

  dp[0][0] = 1;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if(!cek[i][j]){
        dp[i][j] = 0;
      }else{
        if(i>0){
          dp[i][j] += dp[i-1][j];
        }
        if(j>0){
          dp[i][j] += dp[i][j-1];
        }
        dp[i][j] %= MODN;
      }
    }
    
  }
  
  cout << dp[n-1][m-1] << endl;
}