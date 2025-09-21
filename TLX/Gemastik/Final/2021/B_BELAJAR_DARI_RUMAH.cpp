#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  while (n--)
  {
    string s;
    cin >> s;

    int sz = s.length();
    bool ok1 = 0, ok2 = 0;
    vector<int> count(27, 0);
    for (int i = 0; i < sz; i++)
    {
      count[s[i]-'a']++;
    }
    
    for (int i = 0; i < 27; i++)
    {
      if(count[i] == 0){
        continue;
      }

      if(count[i]&1){
        ok1 = 1;
      }
      if(count[i] % 2 == 0){
        ok2 = 1;
      }
    }
    
    if(ok1 && ok2){
      cout << 2 << endl;
    }else if(ok2){
      cout << 0 << endl;
    }else{
      cout << 1 << endl;
    }
  }
  
}