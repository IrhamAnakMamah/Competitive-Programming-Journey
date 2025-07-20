#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int aa = max((3*a)/10, a - ((a*c)/250));
  int bb = max((3*b)/10, b - ((b*d)/250));

  if(aa>bb){
    cout << "Misha" << "\n";
  }else if(bb>aa){
    cout << "Vasya" << "\n";
  }else{
    cout << "Tie" << "\n";
  }
}