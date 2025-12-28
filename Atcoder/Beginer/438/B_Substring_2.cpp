#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n,m;
  cin >> n >> m;

  string s,t;
  cin >> s >> t;

  int ans = INT_MAX;
  for (int i = 0; i <= (n - m); i++)
  {
    int sum = 0;
    for (int j = 0; j < m; j++)
    {
      int idx = i + j;
      if(s[idx] >= t[j]){
        sum += (s[idx] - '0') - (t[j] - '0');
      }else{
        sum += ((s[idx] - '0') + 10) - (t[j] - '0');
      }
    }
    ans = min(ans, sum);
  }
  cout << ans << endl;
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