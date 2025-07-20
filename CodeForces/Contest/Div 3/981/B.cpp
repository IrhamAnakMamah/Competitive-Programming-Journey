#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin >> a[i][j];
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      int mx = 0;
      for (int j = 0; j < n-i; j++)
      {
        if(a[i+j][j] < 0){
          mx = max(mx,abs(a[i+j][j]));
        }
      }
      ans+=mx;
    }
    
    for (int i = 1; i < n; i++)
    {
      int mx = 0;
      for(int j = 0; j<n-i;j++){
        if(a[j][i+j]<0){
          mx = max(mx,abs(a[j][i+j]));
        }
      }
      ans+=mx;
    }
    
    cout << ans << "\n";
  }
  
}