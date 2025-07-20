#include <bits/stdc++.h>
using namespace std;

int main (){
  int n;
  bool ok = 1;
  cin >> n;
  while(n--){
    int a;
    cin >> a;
    if(a==1){
      ok = 0;
    }
  }

  (ok) ? cout << "EASY" << "\n" : cout << "HARD" << "\n";
}