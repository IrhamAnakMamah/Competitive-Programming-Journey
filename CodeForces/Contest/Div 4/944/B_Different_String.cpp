#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    string s;
    bool ok = 1;
    cin >> s;
    for (int i = 1; i < s.length(); i++)
    {
      if(s[i]!=s[i-1]){
        ok = 0;
        char temp = s[i];
        s[i] = s[i-1];
        s[i-1] = temp;
      }
    }
    if(!ok){
      cout << "YES" << endl;
      cout << s << endl;
    }else{
      cout << "NO" << endl;
    }
  }
}