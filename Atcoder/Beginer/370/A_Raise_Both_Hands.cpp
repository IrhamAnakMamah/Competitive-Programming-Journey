#include <bits/stdc++.h>
using namespace std;

int main(){
  int l,r;
  cin >> l >> r;

  if((l && r) || (l == 0 && r == 0)){
    cout << "Invalid" << endl;
  }else if(l){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}