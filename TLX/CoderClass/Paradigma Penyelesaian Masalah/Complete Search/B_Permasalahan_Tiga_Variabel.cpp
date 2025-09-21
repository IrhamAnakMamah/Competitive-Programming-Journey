#include <bits/stdc++.h>
using namespace std;

int a[201];

void precomp(){
  for (int i = 0; i <= 200; i++)
  {
    for (int j = 0; j <= 200; j++)
    {
      for (int k = 0; k <= 200; k++)
      {
        int temp = i + j + k;
        if(temp > 200){
          break;
        }
        a[temp]++;
      }
      
    }
    
  }
  
}

int main(){
  for (int i = 0; i <= 200; i++)
  {
    a[i] = 0;
  }
  
  precomp();

  int n;
  cin >> n;
  cout << a[n] << endl;
}