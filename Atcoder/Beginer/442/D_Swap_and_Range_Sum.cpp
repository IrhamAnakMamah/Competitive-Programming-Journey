#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n, q;
  cin >> n >> q;

  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  vector<ll> pref(n+1, 0);
  for (int i = 1; i <= n; i++)
  {
    pref[i] = pref[i-1] + a[i-1];
  }
  
  while (q--)
  {
    int x;
    cin >> x;
    if(x == 1){
      int i;
      cin >> i;
      
      ll temp1 = a[i-1];
      ll temp2 = a[i];
      pref[i] -= temp1;
      pref[i+1] -= temp2;
      pref[i] += temp2;
      pref[i+1] = pref[i] + temp1;

      swap(a[i-1], a[i]);
    }else{
      int l, r;
      cin >> l >> r;
      cout << pref[r] - pref[l-1] << endl;
    }
  }
  
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