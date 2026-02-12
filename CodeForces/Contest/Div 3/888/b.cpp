#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;

  bool cek[n];
  vector<pair<int,int>> a(n);
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    a[i] = {x, i};
    cek[i] = (x&1);
  }
  
  sort(a.begin(), a.end());
  bool ok = 1;
  for (int i = 0; i < n; i++)
  {
    auto [x,y] = a[i];
    if(y == i) continue;

    if(x&1 != cek[i]) ok = 0;
  }
  cout << (ok ? "Yes" : "No") << endl;
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
