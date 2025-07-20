#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    int n,q;
    cin >> n >> q;
    vector<bool> a(1e5+5,0);
    vector<int> pref(1e5+6,0);
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      a[x-1] = 1;
    }
    
    for (int i = 1; i <= 1e5+1; i++)
    {
      pref[i] = pref[i-1] + a[i-1];
    }
    
    for (int i = 0; i < q; i++)
    {
      int x;
      cin >> x;
      int ans1 = pref[x-1];
      int ans2 = pref[100001]-pref[x];
      cout << ans1 << " " << ans2 << endl;
    }
    
  }
  
}