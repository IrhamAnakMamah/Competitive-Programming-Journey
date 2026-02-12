#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n, m;
  cin >> n >> m;

  vector<int> r(n+1, 0);
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    r[x]++;
    r[y]++;
  }
  
  for (int i = 1; i <= n; i++)
  {
    ll temp = n - r[i] - 1;
    if(temp >= 3){
      ll ans = temp * (temp - 1) * (temp - 2) / 6;
      cout << ans << " ";
    }else{
      cout << 0 << " "; 
    }
  }
  cout << endl;
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