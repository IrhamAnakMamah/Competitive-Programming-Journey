#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    
    int l,r;
    cin >> l >> r;
    int sum = (l/2) + r;
    cout << (sum > n ? n : sum) << endl;
  }
  
}