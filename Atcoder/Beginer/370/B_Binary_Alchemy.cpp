#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int a[n][n];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cin >> a[i][j];
    }
  }
  int elemen = a[0][0];
  for (int i = 1; i < n; i++)
  {
    int temp = i+1;
    if(temp > elemen){
      elemen = a[temp-1][elemen-1];
    }else{
      elemen = a[elemen-1][temp-1];
    }
  }
  cout << elemen << endl;
}