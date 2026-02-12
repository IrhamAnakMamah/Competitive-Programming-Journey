#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  string s;
  cin >> s;

  cout << (s[0] == s[1] && s[1] == s[2] ? "Yes" : "No") << endl;
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
  
}