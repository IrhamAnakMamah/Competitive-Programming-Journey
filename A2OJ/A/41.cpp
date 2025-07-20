#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  ll n,m;
  cin >> n >> m;
  if(n&1)n++;
  if(abs(m-n)>=2){
    cout << n << " " << n+1 << " " << n+2 << "\n";
  }else{
    cout << -1 << "\n";
  }
}