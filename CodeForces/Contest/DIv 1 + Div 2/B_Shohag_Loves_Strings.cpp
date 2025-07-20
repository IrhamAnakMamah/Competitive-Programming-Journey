#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    bool ok = 0;
    string ans = "";
    for (int i = 1; i < s.length(); i++)
    {
      if(i>=2){
        if(s[i]!=s[i-1] && s[i-1]!=s[i-2] && s[i-2]!=s[i]){
          ok = 1;
          ans = s.substr(i-2,3);
          break;
        }
      }
      if(s[i]==s[i-1]){
        ok = 1;
        ans = s.substr(i-1,2);
        break; 
      }
    }
    if(ok){
      cout << ans << endl;
    }else{
      cout << -1 << endl;
    }
  }
  
}