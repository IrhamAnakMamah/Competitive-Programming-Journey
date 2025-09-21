#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  ll n,k,x;
  cin >> n >> k >> x;
  
  x = abs(x);
  if(n*k >= x){
    cout << "YA" << endl;
  }else{
    cout << "TIDAK" << endl;
  }
}