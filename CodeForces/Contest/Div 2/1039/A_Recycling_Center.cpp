#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    ll n,m;
    cin >> n >> m;

    ll a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    
    sort(a,a+n,greater<>());
    ll ans = 0;
    ll kali = 1;
    for (int i = 0; i < n; i++)
    {
      ll temp = a[i] * kali;
      if(temp <= m){
        kali*=2;
      }else{
        ans++;
      }
    }
    
    cout << ans << endl;
    
  }
  
}