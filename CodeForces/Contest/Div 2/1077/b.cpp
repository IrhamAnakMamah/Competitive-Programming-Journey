#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;

  string s;
  cin >> s;

  int cnt = 0;
  bool ok = 0;

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if(s[i] == '1'){
      ok = 1;
      ans++;
      cnt--;
      ans += (((cnt-1) / 3) + (cnt > 0 ? 1 : 0));
      cnt = 0;
    }else{
      if(ok){
        ok = 0;
      }else{
        cnt++;
      }
    }
  }
  ans += (((cnt-1) / 3) + (cnt != 0 ? 1 : 0));
  cout << ans << endl;
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