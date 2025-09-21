#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  char c[n][n];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      c[i][j] = '.';
    }
  }
  
  for (int k = 0; k < (n/2)+1; k+=2)
  {
    int j = k;
    int i = k;
    while (j<(n-k))
    {
      c[i][j] = '#';
      j++;
    }
    j--;
    while (i<(n-k))
    {
      c[i][j] = '#';
      i++;
    }
    i--;
    while (j>=k)
    {
      c[i][j] = '#';
      j--;
    }
    j++;

    while (i>=k)
    {
      c[i][j] = '#';
      i--;
    }
    i++;
    
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << c[i][j];
    }
    cout << endl;
  }
  
}