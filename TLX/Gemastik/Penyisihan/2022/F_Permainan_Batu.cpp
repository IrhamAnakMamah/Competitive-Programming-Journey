#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

ll f(ll x){
  ll temp = x%4;
  if(temp == 0){
    return x;
  }else if(temp == 1){
    return 1;
  }else if(temp == 2){
    return x+1;
  }else{
    return 0;
  }
}

int main(){
  ll n,k,m;
  cin >> n >> k >> m;

  ll ans = 0;
  if(m&1){
    ans = f(n-1) ^ f(n-k-1);
  }

  if(ans == 0){
    cout << "Kedua" << endl;
  }else{
    cout << "Pertama" << endl;
  }
}