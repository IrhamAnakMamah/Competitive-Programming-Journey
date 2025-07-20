#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  char c = 'z';
  int temp = 1;
  int ans = 0;
  for (int i = 0; i < s.length(); i++)
  {
    if(s[i]!=c){
      c = s[i];
      ans = max(ans,temp);
      temp = 1;
    }else{
      temp++;
    }
  }
  ans = max(ans,temp);
  cout << ans << "\n";
}