#include <iostream>
using namespace std;

//  3

//  1 3 0
//  6 2 4
//  2 1 5

//  2 1 7
//  0 0 1
//  1 1 2

int main(){
  int n;
  cin >> n;
  int a[n][n];
  int b[n][n];
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
      cin >> b[i][j];
    }
  }

  int c[n][n];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      c[i][j] = a[i][j] + b[i][j];
    }
  }
  
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << c[i][j] << " ";
    }
    cout << endl;
  }
  
}
