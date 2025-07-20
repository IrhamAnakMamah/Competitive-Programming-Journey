#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  while (n--){
    long long a;
    cin >> a;
    long long ans = a*(a*a+1)/2;
    cout << ans << "\n";
  }
  return 0;
}