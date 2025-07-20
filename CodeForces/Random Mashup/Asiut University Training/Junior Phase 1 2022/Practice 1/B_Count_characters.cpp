#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    vector<int> ans(100,0);
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
      ans[s[i]-'A']++;
    }
    
    for (int i = 0; i < 100; i++)
    {
      if(ans[i]){
        char a = 'A'+ i; 
        cout << a << " " << ans[i] << endl;
      }
    }
    
  }
  
}