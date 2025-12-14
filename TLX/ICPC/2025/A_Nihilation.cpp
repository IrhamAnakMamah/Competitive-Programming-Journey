#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll n;
  cin >> n;
  
  ll g;
  ll mx = 0;
  for (int i = 0; i < n; i++)
  {
    ll a;
    cin >> a;
    mx = max(a, mx);
    if(i == 0){
      g = a;
    }else{
      g = __gcd(g,a);
    }
  }
  
  if(g != 1){
    cout << 1 << endl;
    cout << g << " " << 1 << endl;
  }else{
    cout << 2 << endl;
    if(mx == 1){
      cout << 3 << " " << 2 << endl;
    }else{
      cout << (mx+(mx&1)) << " " << 2 << endl;
    }
    cout << 2 << " " << 1 << endl;
  }
}