#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  ll n,q;
  cin >> n >> q;

  ll sum = 0;
  ll a[n];
  ll b[n];
  ll mn[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }
  
  for (int i = 0; i < n; i++)
  {
    mn[i] = min(a[i], b[i]);
    sum += mn[i];
  }
  
  for (int i = 0; i < q; i++)
  {
    char c;
    int x,y;
    cin >> c >> x >> y;
    if(c == 'A'){
      x--;
      a[x] = y;
    }else{
      x--;
      b[x] = y;  
    }
    if(mn[x] != min(a[x], b[x])){
      sum += (-1 * (mn[x] - min(a[x], b[x])));
      mn[x] = min(a[x], b[x]);
    }
    cout << sum << endl;
  }
  
}