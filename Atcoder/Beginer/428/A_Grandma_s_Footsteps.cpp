#include <bits/stdc++.h>
using namespace std;

int main(){
  int s,a,b,c;
  cin >> s >> a >> b >> c;

  int cnt = 0;
  int ans = 0;
  while (cnt < c)
  {
    if(a + cnt < c){
      ans += s*a;
      cnt += a + b;
    }else{
      ans += s * (c - cnt);
      cnt = c;
    }
  }
  cout << ans << endl;
}