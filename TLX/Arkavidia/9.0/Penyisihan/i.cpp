#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  ll n, k;
  cin >> n >> k;
  if(n < abs(k) || (n - abs(k))&1 || (k <= 0 && abs(k - 2) > n)){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
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
