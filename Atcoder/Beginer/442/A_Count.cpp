#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  string s;
  cin >> s;
  int ans = 0;

  for (int i = 0; i < s.length(); i++)
  {
    if(s[i] == 'i' || s[i] == 'j') ans++;
  }
  cout << ans << endl;
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