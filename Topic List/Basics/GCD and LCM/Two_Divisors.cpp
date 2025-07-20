#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd (ll a, ll b){
  return (b==0 ? a : gcd(b,a%b));
}

int main(){
  int t;
  cin >>t;
  while (t--)
  {
    ll a,b;
    cin >> a >> b;
    ll sum = (a/gcd(a,b))*b;
    if(sum==b){
      cout << (b/a)*b << "\n";
    }else{
      cout << sum << "\n";
    }
  }
  
}