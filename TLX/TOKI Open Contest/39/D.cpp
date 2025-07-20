#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 998244353;

int main(){
  ll n;
  cin >> n;
  ll a[n];
  ll sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum = sum+a[i];
  }

  ll f = 1; 
  for (int i = 3; i <= n; i++)
  {
    f *=i;
    f%=mod;
  }

  ll count = 0;
  for (int i = 0; i < n; i++)
  {

    ll temp1 = a[i]*(a[i]-1)/2;
    temp1 %= mod;
    count+=(temp1*((sum-a[i])%mod))%mod; 
    count%=mod;
  }
  ll ans = (f*count)%mod;
  cout << ans << "\n";
}
