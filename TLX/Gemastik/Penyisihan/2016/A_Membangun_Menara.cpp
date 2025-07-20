#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int mn = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
      int x,y,z;
      cin >> x >> y >> z;
      mn = mn + min({x,y,z});
      mx = mx + max({x,y,z});
    }
    cout << mn << " " << mx << endl; 
  }
  
}