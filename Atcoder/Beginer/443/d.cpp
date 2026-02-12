#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;

  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> h = a;

  for(int i = 1; i < n; i++){
    h[i] = min(h[i], h[i-1] + 1);
  }

  for(int i = n - 2; i >= 0; i--){
    h[i] = min(h[i], h[i+1] + 1);
  }

  ll ans = 0;
  for(int i = 0; i < n; i++){
    ans += (ll)(a[i] - h[i]);
  }

  cout << ans << endl; 
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--)
  {
    solve();
  }
  
  return 0;
}