#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    ll n,x,y;
    cin >> n >> x >> y;

    ll a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    
    map<pair<ll,ll>,ll> mp;
    ll ans = 0;
    for (int i = n-1; i >= 0; i--)
    {
      ll x1 = (a[i] % x);
      ll x2 = (a[i] % y); 
      ll temp = a[i] % x;
      temp = (temp == 0 ? x : temp);
      
      if(mp.find({x - temp, x2}) != mp.end()){
        ans += mp[{x - temp, x2}]; 
      }

      mp[{x1,x2}]++;
    }
    cout << ans << endl;
  }
  

}