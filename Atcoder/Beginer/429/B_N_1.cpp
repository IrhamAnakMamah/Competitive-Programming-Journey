#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;

  int a[n];
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum += a[i];
  }
  
  bool ok = 0;
  for (int i = 0; i < n; i++)
  {
    if(sum - a[i] == m) ok = 1;
  }
  
  cout << (ok ? "Yes" : "No") << endl;
  
}