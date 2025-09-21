#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    if(i == 0) ans = a;
    else{
      ans = ans / __gcd(ans,a) * a;
    }
  }
  cout << ans << endl;
}