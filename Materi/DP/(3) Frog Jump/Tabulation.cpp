#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> dp(n+1,0);
    for (int i = 0; i < n; i++){
      cin >> a[i];
    }
    dp[0]=0;
    for (int i = 1; i < n; i++){
      int left = dp[i-1] + abs(a[i]-a[i-1]);
      int right = INT_MAX;
      if(i>1) right = dp[i-2] + abs(a[i]-a[i-2]);
      dp[i]= min(left,right);
    }
    cout << dp[n-1] << "\n";
  }
  
}