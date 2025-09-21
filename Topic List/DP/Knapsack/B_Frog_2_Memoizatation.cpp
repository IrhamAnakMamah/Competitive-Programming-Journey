#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int n,k;
int a[MAXN];
vector<int> dp(MAXN, -1);

int f(int x){
  if(x == 0){
    return 0;
  }

  if(dp[x] != -1){
    return dp[x];
  }

  int sum = INT_MAX;
  for (int i = 1; i <= k; i++)
  {
    if(x - i >= 0){
      sum = min(abs(a[x] - a[x-i]) + f(x-i), sum);
    }
  }
  
  return dp[x] = sum;
}

int main(){
  cin >> n >> k;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  int ans = f(n-1);
  cout << ans << endl;
}