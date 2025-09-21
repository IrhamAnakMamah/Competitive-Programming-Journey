#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  if(s[2] == '8'){
    cout << (char)(s[0] + 1) << s[1] << 1 << endl;
  }else if(s[0] != '8' || s[1] != '8'){
    cout << s[0] << s[1] << (char)(s[2] + 1) << endl;
  }else{
    cout << s << endl;
  }
}