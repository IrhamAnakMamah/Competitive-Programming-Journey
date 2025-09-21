#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  ll n;
  cin >> n;

  while (n!=1)
  {
    cout << n << " ";
    if(n&1){
      n*=3;
      n++;
    }else{
      n/=2;
    }
  }
  cout << n << endl;
  
  
}