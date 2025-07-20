#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  int n,q;
  cin >> n >> q;

  ll a[n];
  ll sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum += a[i];
  }

  sort(a,a+n, greater<>());
  
  ll b[n+1];
  b[1] = sum;

  ll diskon[n];
  for (int i = 0; i < n; i++)
  {
    diskon[i] = a[i]/2;
  }
  
  for (int i = 2; i <= n; i++)
  {
    ll temp = 0;
    for (int j = i; j <= n; j+=i)
    {
      temp += diskon[j-1];
      // cout << diskon[j] << " " << i << endl;
      // if(j+i > n && j+1 != n-1){
      //   temp+=diskon[n-1];
      // }
    }
    // cout << endl;
    // cout << i << " " << temp << endl;
    b[i] = sum-temp;
    // cout << b[i] << " " << i << endl;
  }

  for (int i = 0; i < q; i++)
  {
    int x;
    cin >> x;
    if(x>n){
      cout << sum << endl;
    }else{
      cout << b[x] << endl;
    }
  }
  
}