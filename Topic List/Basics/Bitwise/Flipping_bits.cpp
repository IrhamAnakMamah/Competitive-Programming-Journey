#include <bits/stdc++.h>
using namespace std;

const unsigned int MAXVAL = (INT_MAX<<1)+1;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    unsigned int n;
    cin >> n;
    unsigned int ans = MAXVAL^n;
    cout << ans << "\n";
  }
  
}