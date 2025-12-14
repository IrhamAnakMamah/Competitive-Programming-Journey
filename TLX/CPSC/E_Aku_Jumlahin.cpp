#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    ll n;
    cin >> n;

    ll k = 2;
    bool ok = 0;
    while ((k * (k-1))/2 <= n)
    {
      if(n == 1) break;
      ll temp = (k * (k-1))/2;
      ll sum = n - temp;

      if(sum % k == 0){
        ll a = sum/k;
        ll b = a + k - 1;

        if(k == 2){
          cout << n << " = " << a << " + " << b << endl;
        }else{
          cout << n << " = " << a << " + ... + " << b << endl;
        }
        ok = 1;
      }
      k++;
      if(ok) break;
    }
    if(!ok) cout << "GAK BISA" << endl;
  }
  
}