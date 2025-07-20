#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    int jarak = n-m+1;
    int ans = 1;

    if(m==n){
      bool ok = 1;
      for (int i = 1; i < n; i+=2)
      {
        if(a[i]!=(i+1)/2){
          ans = (i+1)/2;
          ok = 0;
          break;
        }
      }
      if(ok) ans = (m/2)+1;
    }else{
      bool ok = 1;
      for (int i = 1; i <= jarak; i++)
      {
        if(a[i]!=1){
          ans = 1;
          ok =0;
          break;
        }
      }

      if(ok) ans = 2;
    }
    cout << ans << endl;
  }
  
}