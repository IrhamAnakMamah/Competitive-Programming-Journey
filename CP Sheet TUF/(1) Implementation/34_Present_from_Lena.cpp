#include <bits/stdc++.h>
using namespace std;

int main (){
  int n;
  cin >> n;
  for (int i = -n; i <= n; i++)
  {
    int temp = n - abs(i);
    for (int j = 0; j < abs(i); j++)
    {
      cout << "  ";
    }
    for (int j = 0; j < temp; j++)
    {
      cout << j << " ";
    }
    for (int j = temp; j > 0; j--)
    {
      cout << j << " ";
    }
    cout << 0 << "\n";
  }
  
  
}