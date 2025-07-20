#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,q;
    cin >> n >> q;
    vector<vector<ll>> pref(1005, vector<ll>(1005,0));
    
    vector<vector<ll>> a(1005, vector<ll>(1005,0));

    for (int i = 0; i < n; i++)
    {
      int x,y;
      cin >> x >> y;
      a[x][y]+=x*y;
    }
    
    for (int i =1; i <= 1000; i++)
    {
      for (int j = 1; j <= 1000; j++)
      {
        pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + a[i][j];
      }
    }
    
    for (int i = 0; i < q; i++)
    {
      int x1,x2,y1,y2;
      cin >> x1 >> y1 >> x2 >> y2;
      ll ans = pref[x2-1][y2-1] + pref[x1][y1] - pref[x2-1][y1] - pref[x1][y2-1];
      cout << ans << endl;
    }
    
  }
  
}