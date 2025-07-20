#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a,a+n);
  double ans = 0;
  if(n&1){
    ans = (double)a[(n/2)];
  }else{
    ans = (double)(a[(n/2)]+a[(n/2)-1])/2;
  }

  cout << fixed << setprecision(1) << ans << '\n';
}