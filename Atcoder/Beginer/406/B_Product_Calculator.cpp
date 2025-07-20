#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    ll n,k;
    cin >> n >> k;
    ll cek = 1;
    for (int i = 0; i < k; i++)
    {
      cek*=10;
    }
    cek--;
    ll ans = 1;
    for (ll i = 0; i < n; i++)
    {
      ll a;
      cin >> a;
      if(ans > cek/a){
        ans = 1;
      }else{
        ans*=a;
      }
    }
    cout << ans << endl;
  }
  
}