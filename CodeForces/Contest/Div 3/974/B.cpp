#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int n,k;
    cin >> n >> k;
    int ans = 0;
    if(n&1){
      ans = (k+1)/2;
    }else{
      ans = k/2;
    }

    cout << (ans&1 ? "NO" : "YES") << "\n";
  }
  
}