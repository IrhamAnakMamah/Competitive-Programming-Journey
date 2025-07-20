#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  if((n&1 && m%3!=0) || (n%2==0 && m%2!=0) || n>(m*2)){
    cout << "TIDAK" << endl;
  }else{
    
  }
}