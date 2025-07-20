#include <bits/stdc++.h>
using namespace std;

int main (){
  int n,m,a,b;
  cin >> n >> m >> a >> b;
  int ans1 = n*a;
  int ans2 = min(b,(n%m)*a) + (n/m)*b;
  cout << min(ans1,ans2) << '\n';
}