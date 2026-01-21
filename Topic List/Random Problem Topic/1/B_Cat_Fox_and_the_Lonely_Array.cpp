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
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    
    int ans = n;
    int l = 1;
    int r = n;

    auto cek = [&] (int x){
      int bits[32] = {0}; 
      auto update = [&](int val, int delta) {
          for (int k = 0; k < 30; k++) {
              if ((val >> k) & 1) {
                  bits[k] += delta;
              }
          }
      };

      auto get_current_or = [&]() {
          int res = 0;
          for (int k = 0; k < 30; k++) {
              if (bits[k] > 0) { 
                  res |= (1 << k);
              }
          }
          return res;
      };

      for (int j = 0; j < x; j++) {
          update(a[j], 1);
      }

      int target_sum = get_current_or();
      bool ok = 1;
      for (int i = 1; i <= n - x; i++) {
          update(a[i - 1], -1);
          update(a[i + x - 1], 1);
          
          if (get_current_or() != target_sum) {
              ok = 0;
              break;
          }
      }
      return ok;
    };

    while (l < r)
    {
      int mid = l + (r - l) / 2;
      if(cek(mid)){
        ans = min(mid, ans);
        r = mid;
      }else{
        l = mid + 1;
      }
    }
    cout << ans << endl;
    
  }
  
}