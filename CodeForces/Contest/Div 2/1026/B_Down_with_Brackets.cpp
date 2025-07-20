#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;

    bool ok = 0;
    int sum = 0;
    for (int i = 1; i < (int)s.length()-1; i++)
    {
      if(s[i]=='('){
        sum++;
      }else{
        sum--;
      }

      if(sum<0){
        ok = 1;
      }
    }
    
    if(sum == 0 && !ok){
      ok = 0;
    }else{
      ok = 1;
    }

    cout << (ok ? "YES" : "NO") << endl;
    
  }
  
}