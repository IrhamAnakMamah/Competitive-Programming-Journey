#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  for (int i = 0; i < (int)s.length(); i++)
  {
    if(i == 0) cout << s[i];
    else if(s[i] != s[i-1]) cout << s[i];
  }
  cout << endl;
}