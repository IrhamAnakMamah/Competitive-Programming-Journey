#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    int n,k;
    cin >> n >> k;

    int a[n];

    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    
    vector<int> pref(n+1,0);
    
    for (int i = 1; i <= n; i++)
    {
      pref[i] = pref[i-1] + a[i-1];
    }
    
    for (int i = 0; i < k; i++)
    {
      int b = 0;
      cin >> b;
      int ans = 0;
      ans = upper_bound(pref.begin()+1, pref.end(), b) - (pref.begin() + 1);
      cout << ans << endl;
    }
    
  }
  
}