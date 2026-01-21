#include <bits/stdc++.h>
using namespace std;

void solve(){
  string s;
  cin >> s;

  bool ok = 0;
  for (int i = 0; i < 15; i++)
  {
    if(s.length() == 1 && s[0] == '1'){
      ok = 1;
      break;
    }else{
      int temp = 0;
      for (int j = 0; j < s.length(); j++)
      {
        temp += pow(s[j] - '0', 2);
      }
      s = to_string(temp);
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
  
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

