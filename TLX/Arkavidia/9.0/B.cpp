#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    bool ok = 1;
    for (int i = 0; i < s.length(); i++)
    {
      if(s[i]=='a'){
        if(s.substr(i+1,2) != "ga"){
          ok = 0;
        }else{
          i+=2;
        }
      }else if(s[i] == 'i'){
        if(s.substr(i+1,2) != "gi"){
          ok = 0;
        }else{
          i+=2;
        }
      }else if(s[i] == 'u'){
        if(s.substr(i+1,2) != "gu"){
          ok = 0;
        }else{
          i+=2;
        }
      }else if(s[i] == 'e'){
        if(s.substr(i+1,2) != "ge"){
          ok = 0;
        }else{
          i+=2;
        }
      }else if(s[i] == 'o'){
        if(s.substr(i+1,2) != "go"){
          ok = 0;
        }else{
          i+=2;
        }
      }
    }
    
    cout << (ok ? "Begenagar" : "Sagalagah") << "\n";
  }
  
}