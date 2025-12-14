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

    for (int i = 1; i < n-1; i++)
    {
      int mn = min({a[i-1], a[i]/2, a[i+1]});
      a[i-1] -= mn;
      a[i] -= (mn*2);
      a[i+1] -= mn;
    }
    
    bool ok = 1;
    for (int i = 0; i < n; i++)
    {
      if(a[i] != 0) ok = 0;
    }
    cout << (ok ? "YES" : "NO") << endl;
    
  }
  
}