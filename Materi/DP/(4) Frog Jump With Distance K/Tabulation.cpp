#include <bits/stdc++.h>
using namespace std;

int main (){
  int n,k;
  cin >> n >> k;
  int a[n];
  vector<int> dp(n+1,0);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  dp[0]=0;
  for (int i = 1; i < n; i++)
  {
    int temp = INT_MAX;
    for (int j = 1; j < k; j++)
    {
      if(n-k>=0){
        int jump = dp[i-j] + abs(a[i]-a[i-j]);
        temp = min(temp,jump);
      }
    }
    dp[i] = temp;
  }
  cout << dp[n-1] << "\n";
}