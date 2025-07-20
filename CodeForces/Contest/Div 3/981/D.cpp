#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    vector<ll> pref(n+1);
    for (int i = 1; i <= n; i++)
    {
      pref[i] = pref[i-1] + a[i-1];
    }
    int ans = 0;
    set<ll> seen;
    for (int i = 0; i <= n; i++)
    {
      if(seen.count(pref[i])){
        ans++;
        seen.clear();
      }
      seen.insert(pref[i]);
    }
    cout << ans << "\n";
  }
  

}