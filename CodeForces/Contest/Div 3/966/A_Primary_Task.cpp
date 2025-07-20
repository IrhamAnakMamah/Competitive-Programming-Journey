#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    if(s.length()<3){
      cout << "NO" << "\n";
    }else{
      string temp;
      temp+=s[0];
      temp+=s[1];
      if(temp!="10"){
        cout << "NO" << "\n";
      }else{
        int n = (int)s.length();
        if(n==3 && s[2]-'0'<2){
          cout << "NO" << "\n";
        }else if(n>3 && s[2]=='0'){
          cout << "NO" << "\n";
        }else{
          cout << "YES" << "\n";
        }
      }
    }
  }
  
}