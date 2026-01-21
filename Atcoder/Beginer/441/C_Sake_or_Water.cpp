#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll n, k, x;
  cin >> n >> k >> x;

  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  sort(a, a+n);
  ll temp = 0;
  for (int i = 0; i < k; i++)
  {
    temp += a[i];
  }
  
  if(temp < x){
    cout << -1 << endl;
    return 0;
  }

  ll ans = 0;
  ll notSake = n - k;
  temp = 0;
  for (int i = n-1; i >= 0; i--)
  {
    ans++;
    if(!notSake){
      temp += a[i];
      if(temp >= x){
        break;
      }
    }else{
      notSake--;
    }
  }
  cout << ans << endl;
}