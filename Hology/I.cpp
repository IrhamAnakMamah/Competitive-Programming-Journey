#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 2000 + 5;
ll n, k;
ll a[2000];
vector<vector<ll>> dp(MAXN, vector<ll>(MAXN, -1));

int hitung = 1;

ll f(int index, int loncat){
  if(dp[index][loncat] != -1){
    return dp[index][loncat];
  }

  ll ans = 0;
  if(loncat == 0){
    for (int i = index+1; i < n; i++)
    {
      ans = max(ans, a[i] +  f(i,0));
    }
    
  }else{
    for (int i = index + loncat + 1; i < n; i++)
    {
      ans = max(ans, a[i] + f(i, loncat/2));
    }
    
  }
  return dp[index][loncat] = ans;
}

int main(){
  cin >> n >> k;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans = max(ans,a[i] + f(i, k));
  }
  
  cout << ans << endl;
}