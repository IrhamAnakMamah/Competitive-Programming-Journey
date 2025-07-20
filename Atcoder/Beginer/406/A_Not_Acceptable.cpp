#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;

  //o = no, 1 = yes
  bool ok = 0;

  if(a==c){
    if(b > d){
      ok = 1;
    }else{
      ok = 0;
    }
  }else if(a > c){
    ok = 1;
  }else{
    ok = 0;
  }

  cout << (ok ? "Yes" : "No") << endl;
}