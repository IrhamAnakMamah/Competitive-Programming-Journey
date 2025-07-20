#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const int MAXN = 1e5+1;
ll a[MAXN][3];
vector<vector<ll>> dp(MAXN+1, vector<ll>(3, -1));

ll f(int n, int last){
  if(n==0){
    ll mx = 0;
    for (int i = 0; i < 3; i++)
    {
      if(i!=last){
        mx = max(mx,a[n][i]);
      }
    }
    return mx;
  }

  if(dp[n][last]!=-1){
    return dp[n][last];
  }

  ll mx = 0;
  ll point = 0;
  for (int i = 0; i < 3; i++)
  {
    if(i!=last){
      point = a[n][i] + f(n-1,i);
    }
    mx = max(mx,point);
  }
  return dp[n][last] = mx;
}

int main(){
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> a[i][j];
    }
  }
  
  ll ans = f(n,NULL);
  cout << ans << endl;

}