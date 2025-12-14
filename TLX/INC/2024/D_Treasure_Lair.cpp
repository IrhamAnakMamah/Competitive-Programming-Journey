#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll n,m;
  cin >> n >> m;

  ll a[n][m];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      char c;
      cin >> c;
      a[i][j] = (c == '1');
    }
    
  }
  
  vector<vector<ll>> pref(n+1, vector<ll>(m+1, 0));
  
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      pref[i][j] = a[i-1][j-1] +  (pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1]);
    }
    
  }
  
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      cout << pref[i][j] << " ";
    }
    cout << endl;
  }
  
}