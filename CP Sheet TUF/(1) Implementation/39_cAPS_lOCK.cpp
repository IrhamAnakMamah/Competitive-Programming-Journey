#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  string s;
  bool ok = 1;
  cin >> s;
  string temp = s;

  if(s[0]>='a'){
    temp[0] = s[0] - 32;
  }else{
    temp[0] = s[0] + 32;
  }

  for (int i = 1; i < s.length(); i++)
  {
    if(s[i]<'a'){
      temp[i] = s[i] + 32;
    }else ok = 0;
  }

  if(ok){
    cout << temp << endl;
  }else{
    cout << s << endl;
  }
}