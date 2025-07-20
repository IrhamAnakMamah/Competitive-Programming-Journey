#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  bool ok = 1;
  cin >> s;
  int n = (int)s.length();
  for (int i = 0; i < n/2; i++)
  {
    if(s[i]!=s[n-i-1] && (s[i]!='?' && s[n-i-1]!='?')){
      ok = 0;
    }else if(s[i]!='?' && s[n-i-1]=='?'){
      s[n-i-1] = s[i];
    }else if(s[i]=='?' && s[n-i-1]!='?'){
      s[i] = s[n-i-1];
    }else if(s[i]=='?' && s[n-i-1]=='?'){
      s[i] = 'a';
      s[n-i-1] = 'a';
    }
  }

  if(n&1 && (s[(n/2)]=='?')){
    s[(n/2)] = 'a';
  }

  if(!ok) cout << -1 << '\n';
  else cout << s << "\n";
}