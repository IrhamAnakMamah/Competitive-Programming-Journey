#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;

  string ans = s;
  for (int i = 0; i < s.length(); i++)
  {
    if(s[i] == 'N'){
      ans[i] = 'S';
    }else if(s[i] == 'S'){
      ans[i] = 'N';
    }else if(s[i] == 'E'){
      ans[i] = 'W';
    }else{
      ans[i] = 'E';
    }
  }
  cout << ans << endl;
}