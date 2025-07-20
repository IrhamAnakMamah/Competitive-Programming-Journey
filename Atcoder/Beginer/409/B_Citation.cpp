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
  
  sort(a,a+n, greater<>());

  for (int i = n; i > 0; i--)
  {
    if(a[i-1] >= i){
      cout << i << endl;
      return 0;
    }
  }
  cout << 0 << endl;
}