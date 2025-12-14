#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    if(n&1){
      cout << 0 << endl;
    }else{
      int ans = 0;
      int cnt1 = n;
      while (cnt1 >= 0)
      {
        ans++;
        cnt1-=4;
      }
      cout << ans << endl;
    }
  }
  
}