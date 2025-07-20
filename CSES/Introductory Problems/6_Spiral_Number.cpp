#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
  int t;
  cin >> t;
  while(t--) {
    ll a, b;
    ll sum = 0;
    cin >> a >> b;
    if(b>a) {
      if(b&1) {
        sum = b*b;
        cout << sum - a + 1 << endl;
      }else{
        b--;
        sum = (b*b) +1;
        cout << sum + a - 1 << endl;
      }
    }else{
      if(a&1) {
        a--;
        sum = (a*a)+1;
        cout << sum + b - 1 << endl;
      }else {
        sum = a*a;
        cout << sum - b + 1 << endl;
      }
    }
  }
}