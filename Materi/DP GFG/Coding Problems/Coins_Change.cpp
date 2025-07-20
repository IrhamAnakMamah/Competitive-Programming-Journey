#include <bits/stdc++.h>
using namespace std;
#define ll long long

int f(vector<vector<int>> &dp,vector<int> a, int n, int k){
  if(n<0 || k<=0){
    if(k==0){
      return 1;
    }else return 0;
  }
  
  if(dp[n][k]!=-1){
    return dp[n][k];
  }

  int take = f(dp,a,n,k-a[n]);
  int nottake = f(dp,a,n-1,k);

  return dp[n][k] = take + nottake;
}

int main (){
  int n, k;
  cin >> k >> n;
  vector<int> a(n);
  vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int ans = f(dp,a,n-1,k);
  cout << ans << '\n';
}