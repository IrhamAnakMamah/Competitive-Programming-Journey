#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  string s;
  cin >> s;

  char vokal[] = {'a', 'i', 'u', 'e', 'o'};

  bool ok = 1;
  for (int i = 0; i < (int)s.length(); i++)
  {
    bool ada = 0;
    for(char c : vokal){
      if(c == s[i]) ada = 1;
    }
    
    if(ada){
      if(i + 2 >= (int)s.length()){
        ok = 0;
      }else if(s[i+1] != 'g' || s[i+2] != s[i]){
        ok = 0;
      }
      i+=2;
    }
  }
  cout << (ok ? "Begenagar" : "Sagalagah") << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;

  while (t--)
  {
    solve();
  }
  
  return 0;
}
