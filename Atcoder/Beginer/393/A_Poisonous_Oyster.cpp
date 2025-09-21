#include <bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  cin >> s >> t;

  if(s == t){
    if(s == "sick"){
      cout << 1 << endl;
    }else{
      cout << 4 << endl;
    }
  }else{
    if(s == "sick"){
      cout << 2 << endl;
    }else{
      cout << 3 << endl;
    }
  }
}