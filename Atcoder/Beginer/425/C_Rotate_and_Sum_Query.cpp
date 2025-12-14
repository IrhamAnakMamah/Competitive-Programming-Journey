#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
  int n,q;
  cin >> n >> q;

  int b[n*2];
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    b[i] = a;
    b[i+n] = a;
  }
  
  vector<int> pref(n*2+1, 0);
  for (int i = 1; i <= n*2; i++)
  {
    pref[i] = pref[i-1] + b[i-1];
  }
  
  int k = 0;
  for (int i = 0; i < q; i++)
  {
    int c,l,r;
    cin >> c;
    if(c == 1){
      cin >> l;
      k += l;
      k %= n;
    }else{
      cin >> l >> r;
      int ans = pref[r + k] - pref[k + l - 1];
      cout << ans << endl;
    }
  }
  
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
  }
  
}