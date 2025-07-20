#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  int x,ok = 0;
  cin >> x;
  for (int i = 0; i < n; i++)
  {
    if(x == a[i]){
      ok = 1;
    }
  }
  
  cout << (ok ? "Yes" : "No") << endl;
}