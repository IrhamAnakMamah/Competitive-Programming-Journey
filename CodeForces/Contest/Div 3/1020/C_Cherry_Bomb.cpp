#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  cin >> t;
  while (t--)
  {
    int n,k;
    cin >> n >> k;
    
    int mn = INT_MAX;
    int mx = INT_MIN;
    int temp = INT_MAX;
    int ans = 0;
    bool ok = 1;

    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if(a[i]<mn){
        mn = a[i];
      }
      if(a[i]>mx){
        mx = a[i];
      }
    }
    
    int b[n];
    for (int i = 0; i < n; i++)
    {
      cin >> b[i];
      if(b[i]!=-1){
        if(temp == INT_MAX){
          temp = b[i] + a[i];
        }else if(a[i]+b[i]!=temp){
          ok = 0;
        }
      }
    }

    if(temp < mx){
      ok = 0;
    }

    if(ok){
      if(temp == INT_MAX){
        if(mn+k>=mx){
          ans = k - (mx - mn) + 1;
        }else{
          ans = 0;
        }
      }else{
        if(mn+k>=temp && temp>=mx){
          ans = 1;
        }else{
          ans = 0;
        }
      }
    }else{
      ans = 0;
    }
    cout << ans << endl;
  }
  
}