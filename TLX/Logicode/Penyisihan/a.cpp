#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  ll n, m;
  cin >> n >> m;

  int ans = 0;
  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  ll res = 0;
  int l = -1;
  int r = -1;
  for (int i = 0; i < n; i++)
  {
    if(l == -1){
      if(a[i] <= m && a[i] + res >= 0){
        res += a[i];
        l = i;
        r = i;
      }
    }else{
      if(a[i] + res <= m && a[i] + res >= 0){
        r = i;
        res += a[i];
      }else{
        r = i;
        res += a[i];
        int j = l;
        while ((res < 0 || res > m) && (l <= r))
        {
          res -= a[l];
          l++;
        }
      }
    }
    ans = max(ans, (r == -1 ? 0 : r - l + 1));
    // cout << "i : " << i << ", res : " << res << ", ans : " << ans << endl;
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
  
}