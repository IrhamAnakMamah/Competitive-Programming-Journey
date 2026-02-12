#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  ll n, w;
  cin >> n >> w;

  cout << ((w-1) * (n/w)) + (n - (w * (n/w))) << endl;
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
  
}