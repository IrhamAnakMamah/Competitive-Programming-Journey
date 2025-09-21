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
    ll b[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
      cin >> b[i];
    }

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += (a[i] + b[i]) % m;
    }
    

    vector<ll> cache;
    sort(a, a+n);
    for (int i = 0; i < n; i++)
    {
      cache.push_back(abs((a[i]%m)-m));
    }
    sort(b, b+n, greater<>());
    ll ans = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
      ll temp = ((a[i] % m) + (b[j] % m)) % m;
      if(cache[i] - b[j] <= 0){
        ans += temp;
        j++;
      }else{
        ans+=a[i];
      }
    }
    for (int i = j; i < n; i++)
    {
      ans += b[i];
    }
    cout << ans << endl;
  }
  
}