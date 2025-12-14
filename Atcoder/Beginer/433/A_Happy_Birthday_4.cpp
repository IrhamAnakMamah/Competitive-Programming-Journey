#include <bits/stdc++.h>
using namespace std;

int main(){
  int x,y,z;
  cin >> x >> y >> z;

  if(y * z > x){
    cout << "No" << endl;
  }else{
    int sekarang = y * z;
    while (sekarang < x)
    {
      sekarang+=z;
      x++;
    }
    cout << (sekarang == x ? "Yes" : "No") << endl;
  }
}