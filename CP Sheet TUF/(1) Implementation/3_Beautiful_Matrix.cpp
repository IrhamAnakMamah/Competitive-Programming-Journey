#include <bits/stdc++.h>
using namespace std;

int main (){
  int a,temp1,temp2;
  for(int i = 0; i<5 ;i++){
    for(int j = 0 ; j<5 ; j++){
      cin >> a;
      if(a==1){
        temp1 = i+1;
        temp2 = j+1;
      }
    }
  }
  cout << abs(temp1-3) + abs(temp2-3) << "\n";
}