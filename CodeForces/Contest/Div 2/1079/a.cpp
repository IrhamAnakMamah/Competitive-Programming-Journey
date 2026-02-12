#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int x;
  cin >> x;

  int ans = 0;

  for (int i = x; i <= x + 100; i++)
  {
    int res = i;
    int temp = 0;
    string s = to_string(i);
    for (int i = 0; i < s.length(); i++)
    {
      temp += (s[i] - '0');
    }
    if(res - temp == x) ans++;
  }
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve();
  }
  
}