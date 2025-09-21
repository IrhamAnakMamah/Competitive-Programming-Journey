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

  ll ans = 0;
  for (int i = 0; i < n-1; i++)
  {
    if(a[i] < a[i+1]){
      ans += (a[i+1] - a[i]);
    }
  }
  
  cout << ans << endl;
}