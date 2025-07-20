#include <bits/stdc++.h>
using namespace std;

int main (){
  int n;
  cin >> n;
  while(n--){
    string s;
    cin >> s;
    if(s.length()==1){
      cout << s << "\n";
      continue;
    }
    reverse(s.begin(), s.end());
    int i = 0;
    while(true){
      if(s[i]=='0'){
        s.erase(s.begin()+i);
      }else break;
    }
    cout << s << "\n";
  }
}