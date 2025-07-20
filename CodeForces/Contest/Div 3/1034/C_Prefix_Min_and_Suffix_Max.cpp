#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int a[n+1];
    vector<int> pref(n+1,INT_MAX), suf(n+2,INT_MIN);
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
      pref[i] = min(a[i], pref[i-1]);
    }
    
    for (int i = n; i >=1; i--)
    {
      suf[i] = max(a[i], suf[i+1]);
    }
    
    string s;
    for (int i = 1; i <= n; i++)
    {
      s+=(a[i] == pref[i] || a[i] == suf[i] ? '1' : '0');
    }
    cout << s << endl;
  }
  
}