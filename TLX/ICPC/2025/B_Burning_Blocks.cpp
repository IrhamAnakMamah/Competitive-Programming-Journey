#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n;
  cin >> n;

  int a[n];
  bool zero = 1;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    // if(a[i] != 0) zero = 0;
  }
  
  vector<int> pref(n+1, 0);
  vector<int> suf(n+1, 0);
  pref[0] = min(a[0], 1);
  suf[n-1] = min(a[n-1], 1);

  for (int i = 1; i < n; i++)
  {
    pref[i] = min(pref[i-1] + 1, a[i]);
  }

  for (int i = n-2; i >= 0; i--)
  {
    suf[i] = min(suf[i+1] + 1, a[i]);
  }

  // for (int i = 0; i < n; i++)
  // {
  //   cout << pref[i] << " ";
  // }
  // cout << endl;
  // for (int i = 0; i < n; i++)
  // {
  //   cout << suf[i] << " ";
  // }
  
  // cout << endl;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans = max(ans, min(pref[i], suf[i]));
  }
  cout << ans << endl;
  
}