#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    bool transisi = 0;
    int ans = 1;
    for (int i = 1; i < s.length(); i++)
    {
      if(s[i]!=s[i-1] && !transisi && s[i]=='1'){
        transisi = 1;
      }else if(s[i]!=s[i-1]){
        ans++;
      }
    }
    cout << ans << endl;
  }
  
}