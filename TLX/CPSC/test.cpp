#include <bits/stdc++.h>
using namespace std;

int main(){
  for (int i = 1; i <= 10; i++)
  {
    for (int j = i; j <= 10; j++)
    {
      int temp = 0;
      for (int k = 1; k <= j; k++)
      {
        temp+=k;
      }
      cout << temp << endl;
    }
    
  }
  
}