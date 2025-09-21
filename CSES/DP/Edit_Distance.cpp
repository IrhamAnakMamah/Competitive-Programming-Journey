#include <bits/stdc++.h>
using namespace std;

int main(){
  string s, t;
  cin >> s >> t;

  int n = (int)s.length();
  int m = (int)t.length();

  vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

  // base case : dimana string dari t dihapus, contoh dp[i][0] dimana ada karakter sebanyak i pada string s dan 0 karakter pada string t
  for (int i = 0; i <= n; i++)
  {
    dp[i][0] = i;
  }
  
  for (int i = 0; i <= m; i++)
  {
    dp[0][i] = i;
  }
  

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      // jika sama, maka hasilnya sama saja seperti dp[i-1][j-1]
      if(s[i-1] == t[j-1]){
        dp[i][j] = dp[i-1][j-1];
      }else{
        //replace karakter, 1 operasi
        dp[i][j] = dp[i-1][j-1] + 1;
      }
      // hapus karakter pada string t
      dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
      // hapus karakter pada string s
      dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
    }
    
  }
  cout << dp[n][m] << endl;
}