#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    ll n,k;
    cin >> n >> k;

    ll a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    
    if(k > 1){
      k = (k%2) + 2;
    }

    for (int i = 0; i < k; i++)
    {
      ll mex = -1;
      vector<ll> cache(n+1, 0);
      for (int i = 0; i < n; i++)
      {
        cache[a[i]]++;
      }
      
      for (int i = 0; i <= n; i++)
      {
        if(cache[i] == 0){
          mex = i;
          break;
        }
      }
      
      for (int i = 0; i < n; i++)
      {
        if(cache[a[i]] == 1){
          a[i] = min(a[i], mex);
        }else{
          a[i] = mex;
        }
      }
      
    }
    
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
      ans += a[i];
    }
    cout << ans << endl;
  }
  
}