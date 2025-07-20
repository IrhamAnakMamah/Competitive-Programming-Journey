#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,x;
    cin >> n >> x;
    int mn = INT_MAX;
    int mx = INT_MIN;

    for (int i = 0; i < n; i++)
    {
      int a;
      cin >> a;
      mn = min(a,mn);
      mx = max(a,mx);
    }
    cout << min(abs(x-mx),abs(x-mn)) + mx - mn << endl;
  }
  
}