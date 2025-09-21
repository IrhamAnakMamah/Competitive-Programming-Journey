#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    string ans = "abc";
    cin >> s;

    bool ok = (s == ans);
    
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        if(i==j) continue;
        string t = s;
        swap(t[i], t[j]);
        if(t == ans){
          ok = 1;
        }
      }
      
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
  
}