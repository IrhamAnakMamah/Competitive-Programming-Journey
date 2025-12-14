#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;

  int v = 0;
  int c = 0;
  int y = 0;
  int n = 0;
  int g = 0;
  for (int i = 0; i < (int)s.length(); i++)
  {
    char ch = s[i];
    if(ch == 'A' || ch =='I' || ch =='U' || ch =='E' || ch =='O'){
      v++;
    }else if(ch == 'Y'){
      y++;
    }else if(ch == 'N'){
      n++;
    }else if(ch == 'G'){
      g++;
    }else{
      c++;
    }
  }
  
}