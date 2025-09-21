#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    string s[10];
    for (int i = 0; i < 10; i++)
    {
      cin >> s[i];
    }
    int ans = 0;
    for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 10; j++)
      {
        if(s[i][j] == 'X'){
          int x = min(i, 9-i);
          int y = min(j,9-j);

          int mn = min(x,y);
          mn++;
          ans += mn;
        }
      }
      
    }
    cout << ans << endl;
  }
  
}