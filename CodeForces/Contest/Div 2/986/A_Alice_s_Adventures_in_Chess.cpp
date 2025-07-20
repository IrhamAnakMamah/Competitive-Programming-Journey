#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,a,b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    bool ok = 0;
    // n = y+1,e = x+1,s = y-1,w = x-1
    int x = 0, y = 0;
    for (int k = 0; k < 1101; k++)
    {
      for (int i = 0; i <= n; i++)
      {
        if(x==a && y==b){
          ok = 1;
        }else if(i==n){
          break;
        }
        char c = s[i];
        if(c=='N'){
          y++;
        }else if(c=='E'){
          x++;
        }else if(c == 'S'){
          y--;
        }else if(c=='W'){
          x--;
        }
      }
      if(ok) break;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
  
}
