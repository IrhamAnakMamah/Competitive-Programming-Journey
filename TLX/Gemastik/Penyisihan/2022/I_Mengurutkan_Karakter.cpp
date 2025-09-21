#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  string s;
  string t;

  cin >> s >> t;
  
  int ans  = 0;
  bool ok = 0;

  for (int i = 0; i < n; i++)
  {
    if(s[i] < t[i] && ok){
      ok = 0;
    }else if (s[i] > t[i] && !ok){
      ok = 1;
      ans++;
    }
  }
  
  cout << ans << endl;
}