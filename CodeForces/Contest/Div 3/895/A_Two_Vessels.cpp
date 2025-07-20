#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,m,c;
    cin >> n >> m >> c;
    double temp = (double)(abs(m-n))/2;
    int ans = ceil(temp/c);
    cout << ans << endl;
  }
}