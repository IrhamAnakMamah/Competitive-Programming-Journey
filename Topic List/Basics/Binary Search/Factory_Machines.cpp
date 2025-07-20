#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,k;
const int MAXN = 2e5+5;
ll a[MAXN];

int main(){
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  ll l = 0;
  ll r = (*min_element(a, a+n))*k;
  ll ans = 0;
  while(l<=r){
    ll m = (l+r)/2;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum+=(m/a[i]);
    }
    if(sum>=k){
      ans = m;
      r = m-1;
    }else{
      l = m+1;
    }
  }
  cout << ans << "\n";
}