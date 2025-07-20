#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a,ll b){
  return (b==0 ? a : gcd(b,a%b));
}

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    ll n;
    cin >> n;
    if(n&1){
      ll x = 1;
      for (ll i = 2; i <= sqrt(n); i++)
      {
        if(n%i==0){
          x = n/i;
          break;
        }
      }
      cout << x << " " << n-x << "\n";
    }else{
      cout << n/2 << " " << n/2 << "\n";
    }
  }
  
}