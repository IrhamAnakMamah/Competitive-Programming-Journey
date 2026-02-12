#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;

void solve(){
  int n;
  cin >> n;

  ll w = (n * (n+1))/2;
  if(w&1){
    cout << 0 << endl;
    return;
  }

  w/=2;
  vector<ll> dp((int)w+1, 0);
  dp[0] = 1;

  for (int i = 1; i < n; i++)
  {
    for (int j = w; j >= i; j--)
    {
      dp[j] = (dp[j] + dp[j - i]) % mod;
    }
    
  }

  // for (int i = 1; i <= w; i++)
  // {
  //   cout << dp[i] << " ";
  // }
  // cout << endl;
  cout << dp[w] << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}