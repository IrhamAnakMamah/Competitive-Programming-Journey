#include <bits/stdc++.h>
using namespace std;

int main(){
  int ans = 0;
  string s;
  cin >> s;

  int cnt = 1;

  int n = (int)s.length();

  for (int i = 1; i < n; i++)
  {
    int x = s[i] - '0';
    int y = s[i-cnt] -'0';
    if(x-1 == y){
      int temp1 = x;
      int temp2 = y;
      while (i - cnt >= 0)
      {
        x = s[i+cnt-1] - '0';
        y = s[i-cnt] -'0';
        if(x-1 == y && (temp1 == x && temp2 == y)){
          cnt++;
          ans++;
        }else{
          break;
        }
      }
      i += (cnt-2);
      cnt = 1;
    }
  }
  cout << ans << endl;
}