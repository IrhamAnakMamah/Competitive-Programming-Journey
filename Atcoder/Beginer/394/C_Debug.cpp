#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;

  for (int i = s.length() - 2 ; i >= 0; i--)
  {
    if(s[i+1] == 'A' && s[i] == 'W'){
      s[i+1] = 'C';
      s[i] = 'A';
    }
  }
  cout << s << endl;
  
}