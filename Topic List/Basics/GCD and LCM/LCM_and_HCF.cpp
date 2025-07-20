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
    ll a,b;
    cin >> a >> b;
    ll hcf = gcd(a,b);
    ll lcm = (a/hcf)*b;
    cout << lcm << " " << hcf << "\n";
  }
  
}