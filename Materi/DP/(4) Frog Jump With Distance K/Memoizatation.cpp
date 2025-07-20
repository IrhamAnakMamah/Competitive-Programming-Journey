#include <bits/stdc++.h>
using namespace std;

int f(vector<int > &dp,int a[], int k, int n){
  if(n==0) return 0;
  if(dp[n]!=0) return dp[n];
  int temp = INT_MAX;
  for (int i = 1; i <= k; i++)
  {
    if(n-i>=0){
    int sum = f(dp,a,k,n-i) + abs(a[n]-a[n-i]);
    temp = min(temp,sum);
    }
  }
  dp[n] = temp;
  return dp[n];
}

int main (){
  int n,k;
  cin >> n >> k;
  int a[n];
  vector <int> dp(n+1,0);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int ans = f(dp,a,k,n-1);
  cout << ans << "\n";
}