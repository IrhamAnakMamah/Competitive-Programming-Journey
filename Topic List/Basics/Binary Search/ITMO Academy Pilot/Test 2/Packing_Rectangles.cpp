#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll w,h,n;

bool good(ll div){
  return (div/w)*(div/h) >= n;
}

int main(){
  cin >> w >> h >> n;
  ll l = -1;
  ll r = 1;
  while(!good(r)) r*=2;
  
  while (l+1<r)
  {
    ll sum = (l+r)/2;
    if(good(sum)) r = sum;
    else l = sum;
  }
  cout << r << "\n";
  return 0;
}