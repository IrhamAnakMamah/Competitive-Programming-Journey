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
    
    bool ok = 1;
    sort(a, a+n);

    int ans = 0;
    if(a[1] >= (a[0] * 2)){
      ans = a[1] - a[0];
    }else{
      ans = a[0];
    }
    
    cout << ans << endl;
  }
  
}