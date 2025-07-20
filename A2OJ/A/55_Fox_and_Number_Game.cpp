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
  sort(a,a+n, greater<>());
  while(true){
    int count = 0;
    for (int i = 0; i < n-1; i++)
    {
      if(a[i]>a[i+1]){
        a[i] -=a[i+1];
      }else if(a[i]==a[i+1]){
        count++;
      }
    }
    if(count==n-1){
      break;
    }else
    sort(a,a+n,greater<>());
  }
  int ans = a[0]*n;
  cout << ans << "\n";
}