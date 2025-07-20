#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,x,y;
    cin >> n >> x >> y;
    int mn = min(x,y);
    int ans = ceil((double)n/mn);
    cout << ans << "\n";
  }
  
}