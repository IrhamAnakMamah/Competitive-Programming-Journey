#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,m;
    cin >> n >> m;

    int a[m];
    for (int i = 0; i < m; i++)
    {
      cin >> a[i];
    }

    int ans = n - a[m-1] + 1;
    for (int i = 1; i < m; i++)
    {
      ans = (a[i] == 1 ? 1 : ans);
      
    }
    cout << ans << endl;
    
  }
  
}