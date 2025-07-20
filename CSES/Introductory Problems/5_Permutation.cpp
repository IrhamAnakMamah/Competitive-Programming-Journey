#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  if(n==1) {
    cout << 1 << endl;
  }else if(n<=3) {
    cout << "NO SOLUTION" << endl;
  }else{
    cout << n-1 << " ";
    if(n&1) {
      for(int i = 2; i<=n-3; i+=2) {
        cout << i << " ";
      }
    }else{
      for(int i = 1; i<=n-3; i+=2) {
        cout << i << " ";
      }
    }
    cout << n << " ";
    for(int i = n-2; i>0 ; i-=2) {
      cout << i << " ";
    }
    cout << endl;
  }
}