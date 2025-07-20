#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll n;
  cin >> n;
  cout << 0 << endl;
  for (ll i = 2; i <= n; i++)
  {
    ll move = ((i*i)*((i*i)-1))/2;
    ll del = 4*(i-1)*(i-2);
    cout << move-del << endl;
  }
}