#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd (ll a, ll b){
  return (b==0 ? a : gcd(b,a%b));
}

int main(){
  ll x;
  cin >> x;

  ll a;
  for (ll i = 1; i <= sqrt(x); i++)
  {
    ll sum = (i/gcd(i,x/i))*(x/i);
    if(x%i==0 && sum==x){
      a = i;
    }
  }
  
  cout << a << " " << x/a << '\n';
}