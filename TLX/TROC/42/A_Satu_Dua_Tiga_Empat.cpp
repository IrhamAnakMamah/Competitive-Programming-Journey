#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[5];
  a[0] = 0;
  for (int i = 1; i <= 4; i++)
  {
    a[i] = (a[i-1] + i) % 10;
  }
  cout << a[n] << endl;
}