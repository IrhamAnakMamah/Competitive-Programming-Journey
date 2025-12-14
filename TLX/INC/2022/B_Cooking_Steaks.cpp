#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n;
  cin >> n;

  ll t[n];
  for (int i = 0; i < n-1; i++)
  {
    cin >> t[i];
  }
  t[n-1] = 0;
  
  ll a[n];
  ll b[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }
  
  // mulai dari belakang

  ll stock = 0;
  ll ans = 0;

  for (int i = n-1; i >= 0; i--)
  {
    ans += stock * t[i];
    stock += b[i];
    stock -= min(stock, a[i]);
  }
  
  cout << (stock ? -1 : ans) << endl;
  
}