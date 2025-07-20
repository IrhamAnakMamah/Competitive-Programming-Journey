#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;

    int ans = s.length();
    for (int i = s.length() - 1; i > 0; i--)
    {
      if(s[i] == s[i-1]){
        ans = 1;
        break;
      }
    }
    cout << ans << endl;
  }
  
}