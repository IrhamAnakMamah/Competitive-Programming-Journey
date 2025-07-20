#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &a, vector<int> &dp, int n){
  if(n==0) return 0;
  if(dp[n]!=0) return dp[n];
  int left = f(a,dp,n-1) + abs(a[n]-a[n-1]);
  int right = INT_MAX;
  if(n>1) right = f(a,dp,n-2) + abs(a[n]-a[n-2]);
  dp[n] = min(left,right);
  return dp[n];
}

int main (){
    int t;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      vector<int > a(n);
      vector<int > dp(n+1, 0);
      for (int i = 0; i < n; i++){
        cin >> a[i];
      }
      int ans = f(a,dp,n-1);
      cout << ans << "\n";
    }
}