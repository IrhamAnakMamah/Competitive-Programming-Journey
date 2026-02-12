#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  vector<int> a(5);
  a = {1, 4, 6, 8, 10};
  int it = lower_bound(a.begin(), a.end(), 8) - a.begin();
  cout << it << endl;
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