#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,q;
  cin >> n >> m >> q;

  int col[n][m];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> col[i][j];
    }
    
  }
  
  int a[q];
  for (int i = 0; i < q; i++)
  {
    cin >> a[i];
  }
  
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int cnt = 0;
    for (int j = 0; j < m; j++)
    {
      for (int k = 0; k < q; k++)
      {
        if(col[i][j] == a[k]){
          cnt++;
          break;
        }
      }
      
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}