#include <bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  cin >> s >> t;
  string temp1, temp2;
  int temp = 0;
  int k = 0;
  bool ok = 1;
  for (int i = 0; i < s.length(); i++)
  {
    if(s[i]!=t[i]){
      temp++;
      bool lanjut = 0;
      for (int j = k; j < s.length(); j++)
      {
        if(temp1[j] == t[i] && temp2[j]==s[i]){
          lanjut = 1;
        }
      }
      if(lanjut){
        k++;
        ok = 1;
      }else{
        temp1+=s[i];
        temp2+=t[i];
        ok = 0;
      }
    }
  }
  cout << ((temp==0 || temp==2) && ok ? "YES" : "NO") << "\n";
}