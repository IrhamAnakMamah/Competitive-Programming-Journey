#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;

  bool ok = 1;
  while (b != c)
  {
    if(b == a){
      ok = 0;
    }
    b++;
    if(b == 25){
      b = 0;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
}