#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    ll n,x;
    cin >> n >> x;

    ll a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    sort(a,a+n);
    ll ans = a[0];
    for (ll i = 1; i < n; i++)
    {
      if(x <= 0){
        break;
      }
      if(a[i] == a[i-1]){
        continue;
      }else{
        if(x){
          ans+=min(a[i]-a[i-1], x/i);
          x -= ((i) * (a[i] - a[i-1]));
        }
      }
    }
    if(x > 0){
      // cout << ans << " " << x << endl;
      // for (int i = 0; i < n; i++)
      // {
      //   cout << a[i] << " ";
      // }
      // cout << endl;
      ll atas = x/n;
      ans += atas;
    }
    cout << ans << endl;
  }
  
}