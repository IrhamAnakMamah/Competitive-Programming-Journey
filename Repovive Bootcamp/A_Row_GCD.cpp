#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll n,m;
  cin >> n >> m;

  ll a[n];
  ll b[m];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++)
  {
    cin >> b[i];
  }

  sort(a, a+n);

  ll g;
  if(n != 1){
    g = a[1] - a[0];
  }

  for (int i = 2; i < n; i++)
  {
    g = __gcd(g, a[i] - a[i-1]);
  }
  
  for (int i = 0; i < m; i++)
  {
    if(n == 1){
      cout << a[0] + b[i] << " ";
    }else{
      cout << __gcd(a[0] + b[i], g) << " ";
    }
  }
  
  cout << endl;
  
}