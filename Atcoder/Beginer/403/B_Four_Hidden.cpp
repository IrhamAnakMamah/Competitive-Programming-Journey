#include <bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  cin >> s >> t;

  bool ok = 0;
  for (int i = 0; i < (int)s.length() - (int)t.length() + 1; i++)
  {
    bool temp = 1;
    for (int k = 0; k < (int)t.length(); k++)
    {
      if(s[i+k] == '?'){
        continue;
      }
      if(s[i+k] != t[k]){
        temp = 0;
        break;
      }
    }
    if(temp){
      ok = 1;
      break;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
}