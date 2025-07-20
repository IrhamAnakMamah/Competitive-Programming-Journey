#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  if(n<=19){
    cout << 0 << endl;
  }else if(n>=100){
    cout << 9 << endl;
  }else{
    cout << ((n+1)/10)-1 << endl;
  }
}