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

    ll ans = 0;
    
    string s;
    cin >> s;
    vector<int> l,r;
    for (int i = 0; i < n; i++)
    {
      if(s[i]=='L'){
        l.push_back(i+1);
      }else{
        r.push_back(i+1);
      }
    }
    reverse(r.begin(),r.end());
    int jarak = min(l.size(),r.size());
    for (int i = 0; i < jarak; i++)
    {
      if(l[i]<r[i]){
        ans+=pref[r[i]]-pref[l[i]-1];
        cout << ans << endl;
      }
    }
    cout << endl;
    cout << ans << '\n';
  }
  
}