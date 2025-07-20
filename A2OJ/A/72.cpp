#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> x(n);

  for (auto &a: x) cin >> a;

  vector<pair<int, int>> circles;

  for (int i = 0; i < n - 1; i++) {
    circles.push_back(minmax({x[i], x[i + 1]}));
  }

  bool yes = false;

  for (int i = 0; i < (int) circles.size() - 1; i++) {
    for (int j = i + 1; j < (int) circles.size(); j++) {
      auto kiri = circles[i], kanan = circles[j];

      if (kiri.first == kanan.first || kiri.second == kanan.second) continue;

      if (kanan < kiri) swap(kiri, kanan);

      if (kanan.second < kiri.second) continue;

      if (kanan.first < kiri.second) {
        // cout << kiri.first << " " << kiri.second << endl;
        // cout << kanan.first << " " << kanan.second << endl;
        yes = true;
      }      
    }
  }

  cout << (yes ? "yes" : "no") << endl;

  return 0;
}