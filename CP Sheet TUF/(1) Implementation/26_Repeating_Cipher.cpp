#include <bits/stdc++.h>
using namespace std;

int main (){
  int n,x=1,temp = 1;
  cin >> n;
  string ans = "", s;
  cin >> s;
  for (int i = 0; i < s.length(); i++)
  {
    if(x==temp){
      ans+=s[i];
      temp++;
      x = 1;
    }else x++;
  }
  cout << ans << "\n";
}