#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  int a[2][n];

  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
    
  }
  
  
  int q;
  cin >> q;

  for (int i = 0; i < q; i++)
  {
    char c,d;
    int x,y;

    cin >> c >> x >> d >> y;
    x--,y--;
    int index1 = c - 'A';
    int index2 = d - 'A';

    int temp = a[index1][x];
    a[index1][x] = a[index2][y];
    a[index2][y] = temp;
  }
  
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}