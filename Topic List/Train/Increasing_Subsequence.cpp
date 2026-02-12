#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  vector<ll> d(n+1, 1e9);
  d[0] = -1e9;
  for (int i = 0; i < n; i++)
  {
    int l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
    if(d[l-1] < a[i] && d[l] > a[i]){
      d[l] = a[i];
    }
    for(auto x : d){
      cout << x << " ";
    }
    cout << endl;
  }
  
  ll ans = 0;
  for (int i = 0; i <= n; i++)
  {
    if(d[i] != 1e9) ans = i;
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