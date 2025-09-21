#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  ll n,x,y;
  cin >> n >> x >> y;

  ll ans = 0;

  ll a[n];
  ll b[n];
  vector<pair<ll,ll>> cache;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }

  for (int i = 0; i < n; i++)
  {
    if(a[i] >= x && b[i] >= y){
      ans++;
    }else{
      cache.push_back({a[i], b[i]});
    }
  }
  
  
}