#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
    
  while (t--) {
    int x,y,k;
    cin >> x >> y >> k;
    int temp = min(x,y);
    cout << "0 " << temp << " " << temp << " 0" << endl;
    cout << "0 0 " << temp << " " << temp << endl;
  }
    
  return 0;
}
