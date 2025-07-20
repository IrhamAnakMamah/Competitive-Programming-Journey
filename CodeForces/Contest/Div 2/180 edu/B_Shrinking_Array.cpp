#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int a[n];
    // 0 = naik, 1 = turun
    bool arah = 0;
    bool ok = 0;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if(i >= 1){
        if(a[i] == a[i-1] || abs(a[i] - a[i-1]) == 1){
          ans = 0;
        }
      }
    }
    
    if(ans!=-1){
      cout << ans << endl;
    }else if(n == 2){
      cout << -1 << endl;
    }
    else{
      ans = 0;
      for (int i = 1; i < n-1; i++)
      {
        if(a[i-1] < a[i] && a[i] > a[i+1]){
          ans = 1;
        }else if(a[i-1] > a[i] && a[i] < a[i+1]){
          ans = 1;
        }
      }
      cout << (ans == 1 ? ans : -1) << endl;
    }

    
  }
  
}