#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;

  bool ok = 0;
  for (int i = 0; i < s.length(); i++)
  {
    if(s[i] == '.' && !ok){
      ok = 1;
      s[i] = 'o';
    }else if(s[i] == '#'){
      ok = 0;
    }
  }
  cout << s << endl;
}