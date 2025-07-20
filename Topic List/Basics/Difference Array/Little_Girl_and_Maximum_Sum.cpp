#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a.rbegin(),a.rend());
  ll ans = 0;
  vector<ll> pref(n+1,0);
  for (int i = 0; i < m; i++)
  {
    int l,r;
    cin >> l >> r;
    l--;
    r--;
    pref[l]++;
    pref[r+1]--;
  }
  
  for (int i = 1; i < n; i++)
  {
    pref[i]+=pref[i-1];
  }
  sort(pref.rbegin(),pref.rend());
  for (int i = 0; i < n; i++)
  {
    ans+=(pref[i]*a[i]);
  }
  cout << ans << endl;
}