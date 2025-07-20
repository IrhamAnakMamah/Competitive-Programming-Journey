#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const ll MODN = 1e9+7;

string s[1001];

vector<vector<ll>> dp(1001, vector<ll>(1001, -1));

ll f(int n,int m){
  if(s[n][m] == '#'){
    return 0;
  }
  if(n == 0 && m == 0){
    if(s[n][m] == '.'){
      return 1; 
    }else{
      return 0;
    }
  }

  if(dp[n][m] != -1){
    return dp[n][m];
  }

  ll left = 0;
  ll up = 0;

  if(n-1>=0){
    up += f(n-1,m);
  }
  if(m-1>=0){
    left += f(n,m-1);
  }

  return dp[n][m] = ((left % MODN) + (up % MODN)) % MODN;
}

int main(){
  int n,m;
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    cin >> s[i]; 
  }
  
  ll ans = f(n-1,m-1);
  cout << ans << endl;
}