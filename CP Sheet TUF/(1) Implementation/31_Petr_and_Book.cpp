#include <bits/stdc++.h>
using namespace std;

int main (){
  int n,ans = 0;
  cin >> n;
  int a[8];
  for (int i = 1; i <= 7; i++){
    cin >> a[i];
  }
  while(n>0){
    for (int i = 1; i <= 7; i++)
    {
      if(n<=0){
        break;
      }
      if(n-a[i]!=n){
        ans = i;
        n-=a[i];
      }
    }
  }
  cout << ans << '\n';
}