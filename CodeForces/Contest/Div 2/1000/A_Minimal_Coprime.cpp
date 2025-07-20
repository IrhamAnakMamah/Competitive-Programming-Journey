#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,m;
    cin >> n >> m;
    if(n==1 && n==m){
      cout << 1 << endl;
    }else{
      cout << m-n << endl;
    }
  }
  
}