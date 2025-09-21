#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int a[n-1];
  for (int i = 0; i < n-1; i++)
  {
    cin >> a[i];
  }
  sort(a,a+n-1);
  for (int i = 1; i <= n; i++)
  {
    if(a[i-1] != i){
      cout << i << endl;
      break;
    }
  }
  
}