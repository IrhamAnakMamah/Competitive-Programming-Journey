#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;

  string s[n];

  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }
  
  vector<vector<ll>> grid(n+1, vector<ll>(n+1, 0));
  for (int i = 0; i < n; i++)
  {
    vector<ll> pref(n+1, 0);
    vector<ll> suf(n+2, 0);
    for (int j = 1; j <= n; j++)
    {
      pref[j] = pref[j-1] + (s[i][j-1] == '#');
    }

    for (int j = n-1; j >= 0; j--)
    {
      suf[j+1] = suf[j+2] + (s[i][j] == '.');
    }
    
    for (int j = 0; j <= n; j++)
    {
      grid[i][j] = pref[j] + suf[j+1];
    }
    
  }

  vector<ll> dp1(n+1, 0), dp2(n+1, 0);
  for (int i = 0; i <= n; i++)
  {
    dp1[i] = grid[0][i];
  }
  
  for (int i = 1; i < n; i++)
  {
    vector<ll> sufmn(n+2, 1e18);
    for (int j = n; j >= 0; j--)
    {
      sufmn[j] = min(sufmn[j+1], dp1[j]);
    }
    
    for (int j = 0; j <= n; j++)
    {
      dp2[j] = sufmn[j] + grid[i][j];
    }
    
    dp1 = dp2;
  }
  ll ans = *min_element(dp1.begin(), dp1.end());
  cout << ans << endl;
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