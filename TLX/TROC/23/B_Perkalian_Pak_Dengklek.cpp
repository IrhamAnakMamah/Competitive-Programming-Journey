#include <bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  cin >> s >> t;

  int ans = 0;
  for (int i = 0; i < s.length(); i++)
  {
    for (int j = 0; j < t.length(); j++)
    {
      ans += ((s[i] - '0') * (t[j] - '0'));
    }
  }
  cout << ans << endl;
}