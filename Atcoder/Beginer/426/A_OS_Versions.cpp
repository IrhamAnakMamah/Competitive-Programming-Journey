#include <bits/stdc++.h>
using namespace std;

int main(){
  string s[2];
  cin >> s[0] >> s[1];

  int a[2];
  for (int i = 0; i < 2; i++)
  {
    if(s[i] == "Ocelot"){
      a[i] = 0;
    }else if(s[i] == "Serval"){
      a[i] = 1;
    }else{
      a[i] = 2;
    }
  }
  cout << (a[0] >= a[1] ? "Yes" : "No") << endl;
}