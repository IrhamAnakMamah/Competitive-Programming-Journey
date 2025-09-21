#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,k;
    cin >> n >> k;
    
    int a[n];
    int h[n];

    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
      cin >> h[i];
    }


    int l = 0, sum = 0, mx = 0;
    for (int r = 0; r < n; r++) {
      if (r > 0 && h[r-1] % h[r] != 0) {
        l = r;
        sum = 0;
      }

      sum += a[r];

      while (sum > k && l <= r) {
        sum -= a[l];
        l++;
      }

      mx = max(mx, r - l + 1);
    }
    cout << mx << endl;
  }
  
}