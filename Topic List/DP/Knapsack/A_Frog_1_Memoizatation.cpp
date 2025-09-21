#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN];
int n;

vector<int> dp(MAXN, -1);

int f(int i){
  if(i == 0){
    return 0;
  }

  if(dp[i] != -1){
    return dp[i];
  }

  int kasus1 = abs(a[i] - a[i-1]) + f(i-1);
  int kasus2 = INT_MAX;
  if(i > 1){
    kasus2 = abs(a[i] - a[i-2]) + f(i-2);
  }

  return dp[i] = min(kasus2, kasus1);
}

int main(){
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  int ans = f(n-1);
  cout << ans << endl;
}