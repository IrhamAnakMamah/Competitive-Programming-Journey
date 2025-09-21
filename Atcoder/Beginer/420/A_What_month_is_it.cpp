#include <bits/stdc++.h>
using namespace std;

int main(){
  int x,y;
  int ans = 0;
  cin >> x >> y;
  if(x + y > 12){
    ans = ((x + y) % 12 != 0 ? (x+y)%12 : 12);
  }else{
    ans = x + y;
  }
  cout << ans << endl;
}