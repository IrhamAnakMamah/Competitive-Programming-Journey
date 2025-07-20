#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  ll a,b,c,d;
  cin >> a >> b >> c >> d;

  ll x = a*d;
  ll y = b*c;
  if(x==y){
    cout << "sama" << endl;
  }else if(x>y){
    cout << "lebih besar" << endl;
  }else{
    cout << "lebih kecil" << endl;
  }
}