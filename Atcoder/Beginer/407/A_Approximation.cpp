#include <bits/stdc++.h>
using namespace std;

int main(){
  double a,b;
  cin >> a >> b;

  double temp = a/b;
  double atas = ceil(a/b);
  double bawah = floor(a/b);
  if(abs(temp - atas) < abs(temp-bawah)){
    cout << (int)atas << endl;
  }else{
    cout << (int)bawah << endl;
  }
}