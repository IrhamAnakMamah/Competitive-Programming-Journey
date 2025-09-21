#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  ll n;
  cin >> n;

  ll a = -10;
  ll b = INT_MAX;
  ll c = -10;
  ll d = INT_MAX;

  for (int i = 0; i < n; i++)
  {
    ll x,y;
    cin >> x;
    a = max(a,x);
    b = min(b,x);
    cin >> y;
    c = max(c,y);
    d = min(d,y);
  }

  ll ans = 0;
  ll bagi1 = (a+b)/2;
  ans = max(abs(a-bagi1), abs(b-bagi1));
  ll bagi2 = (c+d)/2;
  ans = max({abs(c-bagi2), abs(d-bagi2), ans});
  cout << ans << endl;
  
}