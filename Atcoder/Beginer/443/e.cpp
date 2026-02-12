#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n, c;
  cin >> n >> c;
  c--; 

  vector<string> s(n);
  for(int i = 0; i < n; i++){
    cin >> s[i];
  }

  vector<vector<bool>> dp(n, vector<bool>(n, false));
  dp[n-1][c] = true;

  vector<int> a(n, -1);
  for(int j = 0; j < n; j++){
    if(s[n-1][j] == '#') a[j] = n-1;
  }

  for(int i = n - 2; i >= 0; i--){
    for(int j = 0; j < n; j++){
      bool kiri = (j > 0 && dp[i+1][j-1]);
      bool tengah = dp[i+1][j];
      bool kanan = (j < n - 1 && dp[i+1][j+1]);

      if(s[i][j] == '.'){
        if(kiri || tengah || kanan) {
          dp[i][j] = true;
        }
      } else {
        int k = a[j];
        if(k == -1){
          if(kiri || tengah || kanan) dp[i][j] = true;
        } else {
          if(dp[k][j]) dp[i][j] = true;
        }
      }
    }
    for(int j = 0; j < n; j++){
      if(s[i][j] == '#') a[j] = i;
    }
  }

  string ans = "";
  for(int j = 0; j < n; j++){
    ans += (dp[0][j] ? '1' : '0');
  }
  cout << ans << endl; 
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--)
  {
    solve();
  }
  
  return 0;
}