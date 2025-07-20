#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int x,y,k,ans = 0;
    cin >> x >> y >> k;
    int temp1 = (y+k-1)/k;
    int temp2 = (x+k-1)/k;
    ans = (temp2 > temp1) ? (temp2+k-1)/k : temp1 + temp1;
    cout << ans << "\n";
  }
  
}