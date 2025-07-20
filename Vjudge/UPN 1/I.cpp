#include <bits/stdc++.h>
using namespace std;


vector<int> dp(1e5,-1);
// int x;

int uhuy (int n, int a[]){
  if(n==0){
    return 0;
  }
  if(dp[n]!=-1){
    return dp[n];
  }

  int temp1 = ((a[n]-a[n-1])*(a[n]-a[n-1])) + uhuy(n-1,a);
  int temp2 = INT_MAX;
  int temp3 = INT_MAX;
  if(n>1){
    temp2 = 3*((a[n]-a[n-2])*(a[n]-a[n-2])) + uhuy(n-2,a);
    temp3 = 3*((a[n]-a[n-2])*(a[n]-a[n-2])) + ((a[n-1]-a[n-2])*(a[n-1]-a[n-2])) + uhuy(n-1,a);
  }

  return dp[n] = min(temp1,min(temp2,temp3));
}

int main (){
  int n;
  cin >> n;
  // x=n-1;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int ans = uhuy(n-1,a);
  cout << ans << "\n";
}