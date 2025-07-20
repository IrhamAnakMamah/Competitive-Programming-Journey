#include <bits/stdc++.h>
using namespace std;

int main(){
  int l,r,ans=0;
  cin >> l >> r;
  for (int i = l; i <= r; i++)
  {
    for (int j = l; j <= r; j++)
    {
      int z = i^j;
      if(z>ans){
        ans = z;
      }
    }
    
  }
  cout << ans << '\n';
}