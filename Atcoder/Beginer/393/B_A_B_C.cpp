#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;

  int ans = 0;
  for (int i = 0; i < s.length(); i++)
  {
    int x = 0;
    int y = 0;
    if(s[i] == 'A'){
      x = i+1;
      for (int j = i+1; j < s.length(); j++)
      {
        if(s[j] == 'B'){
          y = j+1;
          if(j+(y-x) < s.length()){
            if(s[j+(y-x)] == 'C'){
              ans++;
            }
          }
        }
      }
    }
    
  }
  cout << ans << endl;

}