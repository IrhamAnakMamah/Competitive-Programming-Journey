#include <bits/stdc++.h>
using namespace std;

long long a,b,c,d;

int main(){
  cin >> a >> b >> c >> d;

  long long ans = 0;
  if(b == 0){
    if(c == 0){
      ans = (a+d+2)/3;
    }else{
      ans = (a+c+2)/3 + (d+2)/3;
    }
  }else{
    if(c == 0){
      ans = (a+2)/3 + (b+d+2)/3;
    }else{
      ans = (a+2)/3 + (b+c+2)/3 + (d+2)/3;
    }
  }
  cout << ans << endl;

}