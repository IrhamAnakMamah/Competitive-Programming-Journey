#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int a[n*3];
  for (int i = 0; i < n*3; i++)
  {
    cin >> a[i];
  }
  
  sort(a,a+(3*n));
  cout << a[n] << endl;
}