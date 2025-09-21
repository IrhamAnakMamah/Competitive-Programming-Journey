#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> m >> n;

  int q;
  cin >> q;

  int cache[n][m];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cache[i][j] = 0;
    }
  }
  
  for (int i = 0; i < q; i++)
  {
    int a,b,c,d,k;
    cin >> a >> b >> c >> d >> k;
    a--;
    b--;
    c--;
    d--;

    for (int i = b; i <= d; i++)
    {
      for (int j = a; j <= c; j++)
      {
        cache[i][j] = k;
      }
      
    }
    
  }
  
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << cache[i][j];
    }
    cout << endl;
  }
  
}