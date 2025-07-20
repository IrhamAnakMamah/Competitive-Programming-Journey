#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
    
  while(t--) {
    int n, k, a, sum = 0, ans = 0;
    cin >> n >> k;
    for(int i = 0; i<n; i++) {
      cin >> a;
      if(a>=k) {
          sum+=a;
      }
      if(sum!=0 && a==0) {
          ans++;
          sum--;
      }
    }
    cout << ans << "\n";
  
  }
  return 0;
}