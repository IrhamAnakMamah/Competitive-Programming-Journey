#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int n, l = 0, r = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
      if(s[i]=='B'){
        l = i;
        break;
      }
    }
    for (int i = n-1; i >= 0; i--)
    {
      if(s[i]=='B'){
        r = i;
        break;
      }
    }
    cout << r-l+1 << "\n";
  }
  
}