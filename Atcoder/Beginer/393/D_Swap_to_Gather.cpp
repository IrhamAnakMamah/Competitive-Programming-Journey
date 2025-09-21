#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;

  int a = 0;
  for (int i = 0; i < (int)s.length(); i++)
  {
    if(s[i] == '1') a++;
  }

  ll ans = 0;
  ll satu = 0;
  for (int i = 0; i < (int)s.length(); i++)
  {
    if(s[i] == '0'){
      ans += min(satu, a - satu);
    }else{
      satu++;
    }
  }
  cout << ans << endl;
}