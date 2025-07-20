#include <bits/stdc++.h>
using namespace std;

int a[11] = {1,2,5,10,20,50,100,200,500,1000};

int main (){
  int n;
  cin >> n;
  for (int i = 9; i >= 0; i--)
  {
    if(n==0){
      break;
    }else if(n/a[i]!=0){
      cout << a[i] << " " << n/a[i] << "\n";
      n = n%a[i];
    }else continue;
  }
  
}