#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int a[n];
  int b[n];

  int ans = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }
  
  int topi_sekarang = a[0];
  int topi_iklan = a[1];

  for (int i = 2; i < n; i++)
  {
    ans = max(ans, b[i] - topi_sekarang);
    topi_sekarang = min(topi_sekarang,topi_iklan);
    topi_iklan = min(topi_iklan,a[i]);
  }
  
  if(ans == 0){
    cout << "tidak mungkin" << endl;
  }else{
    cout << ans << endl;
  }
}