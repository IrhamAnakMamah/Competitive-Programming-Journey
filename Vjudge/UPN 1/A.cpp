#include <bits/stdc++.h>
using namespace std;

int main (){
  int a;
  int temp1 = 0, temp2 = 0;
  for (int i = 0; i < 9; i++){
    cin >> a;
    temp1+=a;
  }
  
  for (int i = 0; i < 8; i++){
    cin >> a;
    temp2+=a;
  }
  cout << temp1 - temp2 + 1 << "\n";
  return 0;
}