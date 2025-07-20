#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    bool ok = 0;
    int a[n];
    
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    
    for (int i = 0; i < n-1; i++)
    {
      int mn = min(a[i],a[i+1]);
      int mx = max(a[i],a[i+1]);
      if(mn*2>mx){
        ok = 1;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
  
}