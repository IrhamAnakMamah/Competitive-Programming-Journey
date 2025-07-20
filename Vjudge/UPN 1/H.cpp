#include <bits/stdc++.h>
using namespace std;

vector<int> dp(1e5,-1);

int uhuy(int n, int k, int a[]){
  if(n==0){
    return 0;
  }
  if(dp[n]!=-1){
    return dp[n];
  }

  int temp = INT_MAX;
  for (int i = 1; i <= k; i++)
  {
    if(n-i>=0){
      int sum = abs(a[n]-a[n-i])+uhuy(n-i,k,a);
      temp = min(temp,sum);
    }
  }
  return dp[n]=temp;
}

int main (){
  int n,k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int ans = uhuy(n-1,k,a);
  cout << ans << "\n";
}