#include <bits/stdc++.h>
using namespace std;

int main (){
  int n;
  cin >> n;
  int a[n];
  vector<int > dp(n+1,0);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  dp[0] = a[0];
  for(int i = 1;i<n;i++){ //{2,1,4,9}
    int pick = a[i];
    if(i>1)pick+=dp[i-2];

    int notpick = dp[i-1];

    dp[i] = max(pick,notpick);
  }
  cout << dp[n-1] << "\n";
}