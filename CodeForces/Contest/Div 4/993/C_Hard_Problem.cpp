#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int m,a,b,c;
    cin >> m >> a >> b >> c;
    int ans = (min(m,a) + min(m,b)) + (min((m*2)-(min(m,a) + min(m,b)), c));
    cout << ans << endl;
  }
  
}