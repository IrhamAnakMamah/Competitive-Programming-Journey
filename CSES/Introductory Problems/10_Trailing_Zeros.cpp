#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int ans = 0;
  int i = 5;
  while (n!=0)
  {
    ans+=n/i;
    n/=5;
  }
  
  cout << ans << "\n";
  
  return 0;
}