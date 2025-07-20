#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  int n;
  cin >> n;

  ll a[n];

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  sort(a,a+n);

  ll ans = 1;

  for (int i = 0; i < n; i++)
  {
    if(a[i] > ans){
      break;
    }
    ans+=a[i];
  }

  cout << ans << endl;

  
  
}