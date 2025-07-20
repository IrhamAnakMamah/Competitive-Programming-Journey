#include <bits/stdc++.h>
using namespace std;

int main (){
  string s,a;
  bool ok = 0;
  cin >> s;
  for (int i = 0; i < 5; i++)
  {
    cin >> a;
    if(s[0]==a[0] || s[1]==a[1]){
      ok = 1;
    }
  }
  
  (ok) ? cout << "YES" << "\n" : cout << "NO" << "\n";
}