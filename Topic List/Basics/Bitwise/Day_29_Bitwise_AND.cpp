#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,k,ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
      for (int j = i+1; j <= n; j++)
      {
        int z = i&j;
        if(z<k){
          ans = max(ans,z);
        }
      }
    }
    cout << ans << "\n";
  }
  
}