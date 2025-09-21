#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;

  int ans = 1;
  int temp = 1;
  for (int i = 1; i < s.length(); i++)
  {
    if(s[i-1] != s[i]){
      ans = max(ans,temp);
      temp = 1;
    }else{
      temp++;
    }
  }
  ans = max(ans,temp);
  cout << ans << endl;
}