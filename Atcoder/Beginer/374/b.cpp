#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  string s;
  string t;

  cin >> s >> t;

  int idx = 0;
  for (int i = 0; i < min((int)s.length(), (int)t.length()); i++)
  {
    if(s[i] != t[i]){
      idx = i + 1;
      break;
    }
  }
  if(idx == 0){
    if((int)s.length() != (int)t.length()){
      idx = 1 + min((int)s.length(), (int)t.length());
    }
  }
  cout << idx << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;

  while (t--)
  {
    solve();
  }
  
  return 0;
}
