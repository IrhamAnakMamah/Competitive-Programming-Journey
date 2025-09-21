#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  ll n,m;
  cin >> n >> m;
  ll a[n];
  ll sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum+=a[i];
  }
  
  vector<ll> pref(n+1, 0);
  ll ans = 0;

  for (int i = 1; i <= n; i++)
  {
    pref[i] = pref[i-1] + a[i-1];
  }
  
  for (int dist = 0; dist < n-1; dist++)
  {
    int i = 0;
    int j = i+dist;
    while (j<n)
    {
      ll temp = pref[j+1] - pref[i];
      if(temp%m == 0){
        ans++;
      }
      if(i>=1 && j<n-1){
        temp = sum - temp;
        if(temp%m == 0){
          ans++;
        }
      }
      i++;
      j++;
    }
  }
  cout << ans << endl;
}