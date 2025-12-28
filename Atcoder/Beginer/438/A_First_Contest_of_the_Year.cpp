#include <bits/stdc++.h>
using namespace std;

void solve(){
  int d,f;
  cin >> d >> f;

  d -= f;
  cout << 7 - (d%7) << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
  }
  
  return 0;
}