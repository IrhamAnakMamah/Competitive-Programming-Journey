#include <bits/stdc++.h>
using namespace std;

int main(){
  int a[3];
  cin >> a[0] >> a[1];
  int ans = 0;
  for (int i = -1000  ; i < 1000; i++)
  {
    a[2] = i;
    for (int j = 0; j < 3; j++)
    {
      if((a[(j+1) % 3] - a[(j)%3]) == (a[(j+2)%3] - a[(j+1)%3])){
        ans++;
        break;
      }
    }
    
  }
  cout << ans << endl;
}