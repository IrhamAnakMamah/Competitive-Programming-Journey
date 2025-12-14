#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < 2 * n; i++) {
      int x;
      cin >> x;
      mp[x]++;
    }

    int ganjil = 0;
    int genap = 0;

    for (auto i : mp) {
      if (i.second % 2 != 0) {
        ganjil++;
      } else {
        genap++;
      }
    }

    int ans = ganjil + (2 * genap);

    if (ganjil == 0) {
      if (genap % 2 != n % 2) {
        ans -= 2;
      }
    }

    cout << ans << endl;
  }
  
  
}