#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,m,k;
    cin >> n >> m >> k;
    vector<ll> cache(n*m);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cache[i*m+j] = 1LL * (min(i,n-k)-max(i-(k-1),0)+1) * (min(j,m-k)-max(j-(k-1),0)+1);
      }
    }
    sort(cache.begin(),cache.end(), greater<>());
    int w;
    cin >> w;
    vector<ll> a(w);
    for (int i = 0; i < w; i++)
    {
      cin >> a[i];
    }
    sort(a.begin(),a.end(), greater<>());
    ll ans = 0;
    for (int i = 0; i < w; i++)
    {
      ans+=a[i]*cache[i];
    }
    cout << ans << '\n';
  }
  
}