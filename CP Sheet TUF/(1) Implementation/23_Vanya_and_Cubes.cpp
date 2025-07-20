#include <bits/stdc++.h>
using namespace std;

int main (){
  int n,ans = 0,x = 1, i = 1;
  cin >> n;
  while(x<=n){
    x = ((i*i)+i)/2;
    if(x>n) break;

    n-=x;
    i++;
    ans++;
  }
  cout << ans << "\n";
}