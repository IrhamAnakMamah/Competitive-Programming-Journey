#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    ll a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    auto isPrime = [&](ll x){
      bool is_prime = true;

      if (x == 0 || x == 1) {
        is_prime = false;
      }

      for (ll i = 2; i <= x / 2; ++i) {
        if (x % i == 0) {
          is_prime = false;
          break;
        }
      }

      return is_prime;
    };

    auto cek = [&](ll x){
      for(int i = 0; i < n; i++){
        if(a[i] % x != 0){
          return true;
        }
      }
      return false;
    };

    int ans = 1;
    while(!cek(ans) || !isPrime(ans)){
      ans++;
    }
    cout << ans << endl;
  }
  
}