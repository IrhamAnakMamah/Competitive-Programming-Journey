#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    
    int n = (int)s.length();
    for (int i = 0; i < n; i++)
    {
      if(s[i] == 'c'){
        if(i + 1 != n){
          char c = s[i+1];
          if(c != 'y' && c != 'i' && c!= 'e' && c != 'h'){
            cout << "k";
          }else if(c != 'h'){
            cout << "s";
          }else{
            cout << s[i];
            i++;
          }
        }else{
          cout << (s[i] == 'c' ? 'k' : s[i]);
        }
      }else{
        cout << s[i];
      }
    }
    cout << endl;
  }
  
}