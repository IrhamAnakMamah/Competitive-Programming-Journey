#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll n;
  cin >> n;

  ll a[n];
  ll b[n];

  ll sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
    sum += b[i];
  }
  
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans += (a[i] * n) + sum;
  }
  cout << ans << endl;
}