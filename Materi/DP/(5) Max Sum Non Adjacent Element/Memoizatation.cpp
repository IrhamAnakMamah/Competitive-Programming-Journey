#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &dp, int a[], int n){
  if(n==0) return a[n];
  if(n<0) return 0;
  if(dp[n]!=0) return dp[n];
  int pick = a[n] + f(dp,a,n-2);
  int notpick = f(dp,a,n-1);
  dp[n] = max(pick,notpick);
  return dp[n];
}

int main (){
  int n;
  cin >> n;
  int a[n];
  vector<int> dp(n+1,0);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  int ans = f(dp,a,n-1);
  cout << ans <<  "\n";
  return 0;
}