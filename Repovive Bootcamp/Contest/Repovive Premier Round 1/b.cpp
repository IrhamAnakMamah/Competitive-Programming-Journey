#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;

  string s;
  cin >> s;

  int dua = 0;
  int enam = 0;
  int nol = 0;

  bool ok = 1;

  for (int i = 0; i < (int)s.length(); i++)
  {
    if(s[i] == '2'){
      dua++;
    }else{
      if(s[i] == '0'){
        nol++;
      }else{
        if(!dua){
          ok = 0;
          break;
        }else{
          dua--;
        }
      }
    }
  }
  cout << (dua == nol && ok ? "Yes" : "No") << endl;
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
  
}