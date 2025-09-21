#include <bits/stdc++.h>
using namespace std;

int n;
int a[101];
vector<vector<vector<int>>> dp(101, vector<vector<int>>(101, vector<int>(101, -1)));

int f(int idx, int m, int k){
  if(idx < 0){
    return 0;
  }

  if(dp[idx][m][k] != -1){
    return dp[idx][m][k];
  }

  int pick = 0;
  int notpick = 0;
  if(a[idx] <= m){
    pick = 1 + f(idx-1, m - a[idx], k);
  }
  if(k > 0){
    notpick = 1 + f(idx-1, m, k-1);
  }

  return dp[idx][m][k] = max(pick,notpick);
}

int main(){
  int m,k;
  cin >> n >> m >> k;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  reverse(a,a+n);

  int ans = f(n-1,m,k);
  cout << ans << endl;
  
}