#include <bits/stdc++.h>
using namespace std;

int main(){
  //tfc
  string s;
  cin >> s;
  bool ok = 1;
  for (int i = 0; i < s.length(); i++)
  {
    if(s[i]=='T' && i>0){
      ok = 0;
      break;
    }else if(s[i]!='T' && s[i]!='C' && s[i]!='F'){
      ok = 0;
      break;
    }else{
      continue;
    }
  }
  if(ok){
    cout << "YA" << '\n';
  }else{
    cout << "TIDAK" << "\n"; 
  }
}