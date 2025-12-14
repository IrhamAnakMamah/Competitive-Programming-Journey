#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n;
  cin >> n;

  vector<ll> ans(n+2, 0);

  int q;
  cin >> q;

  vector<ll> dif(n+2, 0);
  for (int i = 0; i < q; i++)
  {
    ll l,r,v;
    cin >> l >> r >> v;
    dif[l-1] += v;
    dif[r] -= v;
  }

  for (int i = 1; i <= n; i++)
  {
    ans[i] = ans[i-1] + dif[i-1];
  }
  
  for (int i = 1; i <= n; i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  
}