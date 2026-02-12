#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  string s;
  cin >> s;

  int sz = (int)s.length() - 1;
  string san = "nas";
  bool ok = 1;
  for (int i = 0; i < 3; i++)
  {
    if(san[i] != s[sz]){
      ok = 0;
    }
    sz--;
  }
  cout << (ok ? "Yes" : "No") << endl;
  
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
