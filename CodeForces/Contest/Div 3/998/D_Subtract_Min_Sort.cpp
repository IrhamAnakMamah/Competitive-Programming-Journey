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
    
    for (int i = 0; i < n-1; i++)
    {
      int mn = min(a[i],a[i+1]);
      a[i] -= mn;
      a[i+1] -= mn;
    }
    
    for (int i = 0; i < n-1; i++)
    {
      if(a[i]>a[i+1]) ok = 0;
    }
    
    cout << (ok ? "YES" : "NO") << endl;
  }
  
}