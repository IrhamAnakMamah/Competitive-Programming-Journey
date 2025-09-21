#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int a[n];
  bool ok = 1;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  for (int i = 1; i < n; i++)
  {
    if(a[i] <= a[i-1]){
      ok = 0;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
}