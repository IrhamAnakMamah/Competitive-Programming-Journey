#include <bits/stdc++.h>
using namespace std;

void solve(){
  string s;
  cin >> s;

  int cnt = 0;
  for (int i = 0; i < s.length(); i++)
  {
    if(s[i] == 'Y'){
      cnt++;
    }
  }
  cout << (cnt > 1 ? "NO" : "YES") << endl;
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

  return 0;
}