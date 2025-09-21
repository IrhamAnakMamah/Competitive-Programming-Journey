#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  int n, m;
  cin >> n >> m;

  ll a[n][m];
  ll b[n][m];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
    
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> b[i][j];
    }
    
  }
  
  ll cache;
  ll ans = 0;
  for (int i = 0; i < n-1; i++)
  {
    for (int j = i+1; j < n; j++)
    {
      cache = abs(j-i);
      int temp = 0;
      int sum = 0;
      for (int k = 0; k < m; k++)
      {
        temp = abs(a[i][k] - a[j][k]);
        temp += abs(b[i][k] - b[j][k]);
        sum = max(temp,sum);
      }
      ans = max(ans,cache+sum);
    }
  }
  cout << ans << endl;
}