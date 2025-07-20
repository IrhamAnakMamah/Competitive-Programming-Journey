#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n; 
    int bitval;
    for(int i = 0; i < 32; i+=2) {
      bitval = ((n>>i)&1) | (((n>>(i+1))&1)<<1);
      if(bitval > 0 && bitval < 3){
        n ^= ((1U<<i) | (1U<<(i+1)));
      }
    }
    cout << n << " ";
  }

  cout << '\n';
  
}