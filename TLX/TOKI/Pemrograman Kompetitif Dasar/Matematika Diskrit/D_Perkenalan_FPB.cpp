#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

ll gcd (ll a, ll b) {
  return b ? gcd (b, a % b) : a;
}

int main (){
  ll a,b,c,d;
  cin >> a >> b >> c >>d;

  ll temp = b*d;
  ll atas = a*d + b*c;

  cout << atas/gcd(atas,temp) << " " << temp/gcd(atas,temp) << '\n';
}