#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;

    int ans = 0, x = 0;
    bool ok = 0;
    for (int i = 0; i < s.length(); i++)
    {
      if(s[i]=='1' && !ok) ok = 1;
      else if(s[i]=='1' && ok){
        ans+=x;
        x=0;
      }
      else if(ok) x++;
    }
    cout << ans << '\n';
  }
  
}