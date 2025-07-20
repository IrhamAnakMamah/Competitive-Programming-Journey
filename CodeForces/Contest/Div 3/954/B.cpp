#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int m,n;
    cin >> n >> m;
    int a[n][m];
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
        int mx = 0;
        if(j!=0){
          mx = max(mx,a[i][j-1]);
        }
        if(j!=m-1){
          mx = max(mx,a[i][j+1]);
        }
        if(i!=0){
          mx = max(mx,a[i-1][j]);
        }
        if(i==n-1){
          mx = max(mx,a[i+1][j]);
        }

        if(mx<a[i][j]){
          a[i][j] = mx;
        }
      }
    }
    
    
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cout << a[i][j] << " ";
      }
      cout << "\n";
    }
  }
  
}