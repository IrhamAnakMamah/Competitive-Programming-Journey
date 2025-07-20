#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
  int t;
  cin >> t;
  while(t--) {
    ll a, b;
    cin >> a >> b;
    ll sum = a+b;
    ll mn = min(a, b) ;
    ll mx = max(a, b) ;
    if((sum%3==0) && (a==b || (((mn*2) <= (mx*2)) && ((mn*2) >= mx)))) {
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
}