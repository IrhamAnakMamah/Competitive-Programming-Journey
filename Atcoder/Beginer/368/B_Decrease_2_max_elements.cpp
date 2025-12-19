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
  
  int ans = 0;
  while (true)
  {
    sort(a, a+n, greater<>());
    if(a[1] != 0){
      ans++;
    }else{
      break;
    }
    a[0]--;
    a[1]--;
  }
  cout << ans << endl;
}