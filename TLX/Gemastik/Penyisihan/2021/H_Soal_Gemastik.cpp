#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
const int MODN = 1e9+7;

int main(){
  ll n;
  cin >> n;

  ll a,b,c,d;
  cin >> a >> b >> c >> d;

  ll ans = 6;
  ll x = 5;

  if(a == c || b == d){
    ans = 2;
    x = 4;
  }else if(a == d || b == c){
    ans = 1;
    x = 4;
  }

  for(x; x<=n; x++){
    ans = ((ans % MODN) * (x % MODN)) % MODN;
  }
  cout << ans << endl;
}