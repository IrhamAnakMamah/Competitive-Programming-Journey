#include <bits/stdc++.h>
using namespace std;

// a itu harga dan b itu lembar, ditanyanya berapa banyak max lembar yang bisa didapat
int a[1001], b[1001];

const int MAXN = 1e5+7;

vector<vector<int>> dp;

int f(int n, int m){
  if(n == -1){
    return 0;
  }

  if(dp[n][m] != -1){
    return dp[n][m];
  }

  int pick = 0;
  int notpick = 0;
  if(a[n] <= m){
    pick = b[n] + f(n-1, m - a[n]);
  }
  notpick = f(n-1, m);

  return dp[n][m] = max(pick, notpick);
}

int main(){
  int n,m;
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }

  dp.resize(n+1, vector<int>(m+1, -1));
  
  int ans = f(n-1,m);
  cout << ans << endl;

}