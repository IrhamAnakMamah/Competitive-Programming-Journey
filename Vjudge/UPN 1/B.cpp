#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, x = 0, y = 0;
  cin >> n;
  char a[n][n],b;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
  }
  
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> b;
      if(b!=a[i][j]){
        x = i+1;
        y = j+1;
      }
    }
  }
  cout << x << " " << y << "\n";
  return 0;

}