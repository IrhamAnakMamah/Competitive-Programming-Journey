#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  cin >> t;
  while (t--)
  {
    string s;
    int ans = 0;
    cin >> s;
    bool ok = 0;
    for (int i = s.length()-1; i >= 0; i--)
    {
      if(s[i]!='0'){
        ok = 1;
      }else if(ok){
        ans++;
      }
    }
    cout << (int)s.length() - (ans + 1) << endl;
  }
  
}