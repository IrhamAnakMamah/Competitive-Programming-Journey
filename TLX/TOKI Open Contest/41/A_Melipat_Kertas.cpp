#include <bits/stdc++.h>
using namespace std;

int main(){
  int x,y,z;
  cin >> x >> y >> z;
  int sum = x*y;
  bool ok = 0;
  int a = floor((double)sum/z);
  int b = ceil((double)sum/z);
  ok = (a==b && ((a&(a-1))==0));
  cout << (ok ? "YA" : "TIDAK") << endl;
}