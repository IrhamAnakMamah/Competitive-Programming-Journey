#include <bits/stdc++.h>
using namespace std;

int main (){
  int n,i = 2;
  cin >> n;
  while(n>1){
    bool ok = 0;
    int cnt = 0;
    if(n%i==0){
      while(true){
        n/=i;
        cnt++;
        if(n%i!=0){
          break;
        }
      }
      cout << i;
      if(cnt>1)
        cout << "^" << cnt;
      ok = 1;
    }
    i++;

    if(ok && n!=1){
      cout << " x ";
    }
  }
  cout << "\n";
}