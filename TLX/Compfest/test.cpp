#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  if(n==1){
    cout << 3 << endl;
  }else if(n==2){
    cout << 5 << endl;
  }else{
    int ans = 6;
    ans = ans + (n-3) + (n/3);
    cout << ans << endl;
  }
}