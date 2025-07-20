#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  int n,m,q;
  cin >> n >> m >> q;
  ll a[n][m];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
    
  }
  vector<vector<ll>> pref(n+1, vector<ll>(m+1,0));

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      pref[i][j] = a[i-1][j-1] + pref[i-1][j] + (pref[i][j-1] - pref[i-1][j-1]);
    }
  }
  
  for (int i = 0; i < q; i++)
  {
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll ans = pref[x2][y2] + pref[x1-1][y1-1] - pref[x2][y1-1] - pref[x1-1][y2];
    cout << ans << endl;
  }
  
}