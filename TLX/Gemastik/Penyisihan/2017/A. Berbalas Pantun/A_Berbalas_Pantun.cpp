#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main (){
  ll n;
  cin >> n;
  ll a[n];
  ll b[n];
  for (int i = 0; i < n; i++){
    cin >> a[i] >> b[i];
  }
  ll temp = 0;
  for (int i = 0; i < n; i++){
    temp += b[i];
  }
  ll ans = 0;
  for (int i = 0; i < n; i++){
    ans += (temp + (a[i]*n));
  }
  cout << ans << endl;
}