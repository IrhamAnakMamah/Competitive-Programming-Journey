#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool comp(ll &a, ll &b){
  if(a == 0){
    return false;
  }else if(b == 0){
    return true;
  }
  return a<b;
}

int main(){
  ll n,m,c;
  cin >> n >> m >> c;

  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  sort(a, a+n, comp);

  vector<ll> cache;
  ll sum = 1;
  for (int i = 1; i < n; i++)
  {
    if(a[i] != a[i-1]){
      cache.push_back(sum);
      sum = 1;
    }else{
      sum++;
    }
  }
  cache.push_back(sum);

  ll hitung = 0;
  ll sumAll = 0;
  for (int i = 0; i < (int)cache.size(); i++)
  {
    ll sum = cache[i];
    for (int j = i+1;; j++)
    {
      if(sum >= c){
        hitung++;
        break;
      }else{
        sum += cache[j%(int)cache.size()];
      }
    }
    sumAll += sum;
    if(hitung == m){
      break;
    }
  }

  ll ans = sumAll;
  m-=hitung;
  ans += sumAll * (m/hitung);
  m%=hitung;
  
  for (int i = 0; i < (int)cache.size() && m; i++)
  {
    ll sum = cache[i];
    for (int j = i+1;; j++)
    {
      if(sum >= c){
        m--;
        break;
      }else{
        sum += cache[j%(int)cache.size()];
      }
    }
    ans += sum;
  }
  cout << ans << endl;
}