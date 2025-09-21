#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  getline(cin,s);

  string t = "halo dunia";
  int ans = 0;

  for (int i = 0; i < s.length(); i++)
  {
    if(s[i] == ' ') continue;
    else{
      if(s[i] < 'a'){
        char c = s[i];
        s[i] = c + ('a' - 'A'); 
      }
    }
  }

  for (int i = 0; i < 10; i++)
  {
    ans += (s[i] == t[i]);
  }
  cout << ans << endl;
}