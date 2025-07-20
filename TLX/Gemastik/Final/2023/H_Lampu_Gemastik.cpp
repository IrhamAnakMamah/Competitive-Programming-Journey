#include <bits/stdc++.h>
using namespace std;

int main (){
  int n,jumlah = 0, ok = 0;
  cin >> n;
  vector< int> a(n);

  for(auto &b : a){
    cin >> b;
  }

  for (int i = n-1; i >= 0; i--)
  {
    if(ok != a[i]){
      jumlah++;
      ok ^= 1;
    }
  }
  cout << jumlah << "\n";
}