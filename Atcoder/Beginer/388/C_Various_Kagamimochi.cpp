#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll n;
  cin >> n;
  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  ll ans = 0;
  ll i = 0;
  ll j = 0;

  while (j<n)
  {
    if(a[i]<=a[j]/2){
      ans+=n-j;
      i++;
    }else{
      j++;
    }
  }
  
  cout << ans << endl;
}