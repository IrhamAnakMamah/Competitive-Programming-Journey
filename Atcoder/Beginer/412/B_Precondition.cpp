#include <bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  cin >> s >> t;
  bool ok = 1;
  for (int i = 1; i < (int)s.length(); i++)
  {
    if(s[i] >= 'A' && s[i] <= 'Z'){
      char temp = s[i-1];
      bool ada = 0;
      for (int j = 0; j < (int)t.length(); j++)
      {
        if(t[j] == temp){
          ada = 1;
          break;
        }
      }
      if(ok){
        ok = ada;
      }
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
}