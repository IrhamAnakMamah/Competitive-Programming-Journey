#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  ll n, l, r;
  cin >> n >> l >> r;

  ll idx = l;
  vector<int> a(n+1, 0);
  vector<int> sum(n+1, 0);
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    sum[i] = sum[i-1] ^ a[i];
  }

  if(idx <= n){
    cout << a[idx] << endl;
    return;
  }

  ll k = idx/2;
  ll x;
  if(n&1){
    x = sum[n];
  }else{
    x = sum[n] ^ sum[n/2];
  }
  ll res = 0;

  while (k > n)
  {
    if(k&1){
      res ^= x;
      k = 0;
    }else{
      res^=x;
      k/=2;
    }
  }
  
  if(k > 0){
    res ^= sum[k];
  }

  cout << res << endl;
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
