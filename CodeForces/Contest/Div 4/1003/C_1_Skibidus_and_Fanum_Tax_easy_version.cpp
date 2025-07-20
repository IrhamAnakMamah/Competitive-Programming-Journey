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
    int b[m];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
      cin >> b[i];
    }
    
    bool ok = 1;
    int x[n];
    for (int i = 0; i < n; i++)
    {
      x[i] = b[0] - a[i];
    }
    
    int sum[n];

    for (int i = 0; i < n; i++)
    {
      int mx = max(a[i], x[i]);
      int mn = min(a[i], x[i]);
      if(i == 0){
        if(n == 1){
          if(mn <= a[i+1]){
            sum[i] = mn;
          }else{
            ok = 0;
          }
        }else{
          sum[i] = mn;
        }
      }else{
        if(i != n-1){
          if(mn >= sum[i-1] && (mn <= a[i+1] || mn <= x[i+1])){
            sum[i] = mn;
          }else if(mx >= sum[i-1] && (mx <= a[i+1] || mx <= x[i+1])){
            sum[i] = mx;
          }else{
            ok = 0;
          }
        }else{
          if(mn >= sum[i-1]){
            sum[i] = mn;
          }else if(mx >= sum[i-1]){
            sum[i] = mx;
          }else{
            ok = 0;
          }
        }
      }
    }

    cout << (ok ? "YES" : "NO") << endl;
  }
  
}