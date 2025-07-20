#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int count = 0;
  while (true)
  {
    count++;
    n++;
    bool ok = 0;
    string s = to_string(n);
    int j = s.length();
    for (int i = 0; i < j; i++)
    {
      if(s[i]=='8'){
        ok = 1;
      }
    }
    if(ok){
      cout << count << "\n";
      return 0;
    }
  }
  
  
}