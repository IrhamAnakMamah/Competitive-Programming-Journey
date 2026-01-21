#include <bits/stdc++.h>
using namespace std;

const int MAX_VAL = 65536;
bool vis[MAX_VAL];

void solve() {
  int n;
  cin >> n;

  int limit = (1 << n);
  for(int i = 0; i < limit; i++) {
    vis[i] = false;
  }
  vector<int> a;
  int curr = limit - 1;
  while (curr > 0) {
    a.push_back(curr);
    curr >>= 1;
  }
  a.push_back(0);
  for (int s : a) {
    for (int x = 0; x < limit; x++) {
      if (!vis[x]) {
        if ((x & s) == s) {
          cout << x << " ";
          vis[x] = true;
        }
      }
    }
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
    
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}