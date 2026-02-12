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
  
  for (int i = 0; i < n; i++)
  {
    ll b;
    cin >> b;
    a[i] = max(b, a[i]);
  }

  for (int i = n-2; i >= 0; i--)
  {
    if(a[i] < a[i+1]){
      a[i] = a[i+1];
    } 
  }
  
  vector<ll> pref(n+1, 0);
  for (int i = 1; i <= n; i++)
  {
    pref[i] = pref[i-1] + a[i-1];
  }
  
  while (q--)
  {
    int l, r;
    cin >> l >> r;
    cout << pref[r] - pref[l-1] << " "; 
  }
  cout << endl;

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