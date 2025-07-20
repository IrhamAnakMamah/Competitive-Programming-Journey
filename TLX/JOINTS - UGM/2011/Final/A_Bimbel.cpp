#include <bits/stdc++.h>
using namespace std;

int main (){
  int n,m;
  cin >> n >> m;
  cout << (n/m)*(m-1) + (n%m) + 1 << "\n";
}