#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int ans = -1;
    for (int i = 0; i < 30; i++)
    {
      int y = (1<<i) - 1;
      int z = n^y;
      if((y<n) && (n + y > z) && (n + z > y) && (z + y > n)){
        ans = y;
        break;
      }
    }
    cout << ans << endl;
  }
  
}