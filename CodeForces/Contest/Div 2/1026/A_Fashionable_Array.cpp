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
    sort(a,a+n);
    if((a[0] + a[n-1])%2==0){
      cout << 0 << endl;
    }else{
      int ans = n-1;
      for (int i = 1; i < n-1; i++)
      {
        if(a[i]%2 != a[0]%2){
          ans = min(ans,i);
        }
        if(a[i]%2 != a[n-1]%2){
          ans = min(ans,n-i-1);
        }
      }
      cout << ans << endl;
    }
  }
  
}