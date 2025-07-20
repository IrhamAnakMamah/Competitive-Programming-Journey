#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main (){
  int n,m;
  cin >> n >> m;
  int a[n];
  int b[m];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++)
  {
    cin >> b[i];
  }

  sort(a,a+n);
  sort(b,b+m);

  int atas1 = 0, bawah1 = 0, ans = 0;
  for (int i = 0; i < min(n,m); i++) {
    int temp = b[i]-a[n-i-1];
    if(ans+temp < ans){
      ans+=temp;
  }
  
  cout << ans << '\n';
}