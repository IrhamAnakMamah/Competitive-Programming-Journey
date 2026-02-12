#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n, m, k, h;
  cin >> n >> m >> k >> h;

  map<int,bool> mp;
  for (int i = 1; i < m; i++)
  {
    mp[k*i] = 1;
  }
  
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    if(mp.find(abs(a - h)) != mp.end()){
      ans++;
    }
  }
  
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
