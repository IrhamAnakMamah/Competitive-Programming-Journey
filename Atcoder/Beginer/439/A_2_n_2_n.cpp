#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin >> n;
  cout << pow(2,n) - (2 * n) << endl;
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

