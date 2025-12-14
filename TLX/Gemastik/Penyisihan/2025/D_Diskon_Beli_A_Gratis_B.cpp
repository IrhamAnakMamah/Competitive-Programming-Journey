#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n, a, b;
  cin >> n >> a >> b;

  ll x[n];
  for (int i = 0; i < n; i++)
  {
    cin >> x[i];
  }
  
  sort(x, x+n, greater<>());
  ll ans = 0;
  
  int i = 0;
  while (i < n)
  {
    if(i + a + b <= n){
      for (int k = i; k < i+a; k++)
      {
        ans += x[k];
      }
      i += (a + b);
    }else{
      ans += x[i];
      i++;
    }
  }
  cout << ans << endl;
  
}