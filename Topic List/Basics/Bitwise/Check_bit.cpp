#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  if(n&(1<<k)){
    cout << "true\n";
  }else{
    cout << "false\n";
  }
}