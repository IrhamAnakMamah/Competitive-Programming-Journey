#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  vector<int> a(27,0);
  for (int i = 0; i < s.length(); i++)
  {
    a[s[i]-'a']++;
  }
  
  for (int i = 0; i < 27; i++)
  {
    if(a[i] == 0){
      cout << (char)('a' + i) << endl;
      break;
    }
  }
  
}