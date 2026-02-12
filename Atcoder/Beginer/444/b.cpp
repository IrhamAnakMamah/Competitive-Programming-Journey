#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n, k;
  cin >> n >> k;
  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    string s;
    s = to_string(i);
    int res = 0;
    for (int j = 0; j < s.length(); j++)
    {
      res += (s[j] - '0');
    }
    if(res == k) ans++;
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
  
}