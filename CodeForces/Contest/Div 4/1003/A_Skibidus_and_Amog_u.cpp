#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    string ans = s.substr(0,s.length() - 2) + "i";
    cout << ans << endl;
  }
  
}