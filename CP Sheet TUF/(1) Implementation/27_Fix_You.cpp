#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int n,m,ans = 0;
    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> a[i][j];
      }
    }
    for (int i = 0; i < n; i++)
    {
      if(a[i][m-1]=='R'){
        ans++;
        a[i][m-1]=='D';
      }
    }
    for (int j = 0; j < m; j++)
    {
      if(a[n-1][j]=='D'){
        ans++;
        a[n-1][j]=='R';
      }
    }
    cout << ans << "\n";
  }
  
}