#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;

    int ans = s[0] - '0';
    for (int i = 1; i < s.length(); i++)
    {
      ans = min(ans, s[i] - '0');
    }
    cout << ans << endl;
  }
  
}