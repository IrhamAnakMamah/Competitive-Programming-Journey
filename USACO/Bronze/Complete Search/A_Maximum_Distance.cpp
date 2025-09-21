#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int x[n];
  int y[n];
  for (int i = 0; i < n; i++)
  {
    cin >> x[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> y[i];
  }

  int ans = 0;
  int dx, dy;
  for (int i = 0; i < n; i++)
  {
    for (int j = i+1; j < n; j++)
    {
      dx = x[i] - x[j];
      dy = y[i] - y[j];
      ans = max(ans, dx*dx + dy*dy);
    }
    
  }
  cout << ans << endl;
  
}