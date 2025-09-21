#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    ll a,b;
    cin >> a >> b;
    if(a%2==0 && b&1){
      cout << -1 << endl;
    }else if(a&1 && (b%2==0 && b%4!=0)){
      cout << -1 << endl;
    }else{
      if(a&1 && b&1){
        cout << a*b+1 << endl;
      }else{
        cout << (a*(b/2) + b/(b/2)) << endl;
      }
    }
  }
  
}