#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    int ans = INT_MAX;
    for (int i = 0; i < 3; i++)
    {
      int temp = 0;
      for (int j = 0; j < 3; j++)
      {
        temp+=abs(a[i]-a[j]);
      }
      ans = min(ans,temp);
    }
    cout << ans << "\n";
  }
  
}