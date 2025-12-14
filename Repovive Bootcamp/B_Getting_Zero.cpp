#include <bits/stdc++.h>
using namespace std;

const int m = 32768;

int main(){
  int n;
  cin >> n;
  while (n--)
  {
    int a;
    cin >> a;
    int temp = a;
    int ans = INT_MAX;
    for(int i = 0; i<32; i++) {
      temp = a + i;
      int cnt = 0;
      while (temp != 0)
      {
        temp <<= 1;
        temp %= m;
        cnt++;
      }
      ans = min(ans, cnt + i);
    }
    
    ans = min(ans, m - a);
    cout << ans << " ";
  }
  cout << endl;
}