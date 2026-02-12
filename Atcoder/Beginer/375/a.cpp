#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;
  
  string s;
  cin >> s;

  int ans = 0;
  for (int i = 0; i < n-2; i++)
  {
    if(s[i] == '#' && s[i+2] == '#' && s[i+1] == '.'){
      ans++;
    }
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