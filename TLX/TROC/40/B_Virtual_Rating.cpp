#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  ll n,x,y,k;
  cin >> n >> x >> y >> k;

  if(max(x,y) + n == k || max((ll)0,min(x,y) - n) == k){
    cout << "YA" << endl;
  }else{
    cout << "TIDAK" << endl;
  }
}