#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  ll x,y;
  cin >> x >> y;

  ll ans;
  for (int i = 3; i <= 10; i++)
  {
    ans = x + y;
    string s = to_string(ans);
    reverse(s.begin(), s.end());
    ans = stoll(s);

    x = y;
    y = ans;
  }
  cout << ans << endl;
}