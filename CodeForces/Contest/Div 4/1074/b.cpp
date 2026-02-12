#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;

  int mx = 0;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    mx = max(a, mx);
  }
  cout << mx * n << endl;
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