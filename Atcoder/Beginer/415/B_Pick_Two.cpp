#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;

  int x = -1, y = -1;
  int cnt = 0;
  for (int i = 0; i < s.length(); i++)
  {
    if(s[i] == '#'){
      if(x == -1){
        x = i+1;
      }else{
        y = i+1;
      }
      if(y != -1){
        cout << x << "," << y << endl;
        x = -1;
        y = -1;
      }
    }
  }
  
}