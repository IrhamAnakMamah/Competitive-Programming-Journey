#include <bits/stdc++.h>
using namespace std;

int main (){
  int n,x,y,z;
  cin >> n >> x >> y >> z;
  if((x>y && (z>x || z<y)) || (y>x && (z>y || z<x))){
    cout << "No" << "\n";
  }else cout << "Yes" << "\n";
}