#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  ll n,q;
  cin >> n >> q;

  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  vector<ll> pref(n+1, 0);
  for (int i = 1; i <= n; i++)
  {
    pref[i] = pref[i-1] + a[i-1];
  }
  
  for (int k = 0; k < q; k++)
  {
    int l,r;
    cin >> l >> r;
    
    ll ans = 0;
    if(r - l + 1 > 1){
      int temp = r - l + 1;
      int iter = (temp+1)/2;
      for (int i = 0; i < iter; i++)
      {
        ans += (pref[r] - pref[l-1])*temp;
        temp-=2;
        l++;
        r--;
      }
      cout << ans << endl;
    }else{
      cout << pref[r] - pref[l-1] << endl;
    }
  }
  
}