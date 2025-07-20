#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int k,n;
    cin >> k >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    sort(a,a+n);
    int ans = 0;
    for(int i = 0; i<n-1 ; i++){
      ans+=(a[i]*2)-1;
    }
    cout << ans << "\n";
  }
  
}