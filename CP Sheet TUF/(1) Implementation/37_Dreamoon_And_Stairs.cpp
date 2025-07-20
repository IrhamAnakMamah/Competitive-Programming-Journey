#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int n,m, ans = -1;
  cin >> n >> m;

  int sum = n/2;
  if(n%2==1){
    sum += 1;
  }

  while(sum <= n){  
    if(sum%m == 0){
      ans = sum;
      break;
    }else{
      sum++;
    }
  }

  cout << ans << "\n";
}