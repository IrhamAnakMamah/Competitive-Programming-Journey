#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 1e5+5;

ll n,k;
ll a[MAXN];

bool check(ll t){
  ll temp = 0;
  for (int i = 0; i < n; i++)
  {
    if(t > a[i]){
      temp += abs(a[i] - t);
    }
  }
  return temp <= k;
}

int main(){
  cin >> n >> k;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  ll res = 0;

  ll l = 0;
  ll r = 1e18;
  while(l <= r){
    ll mid = l + (r - l) / 2;
    if(check(mid)){
      res = mid;
      l = mid + 1;
    }else{
      r = mid - 1;
    }
  }
  cout << res << endl;
}