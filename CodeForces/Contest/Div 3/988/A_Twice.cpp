#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int a[n];
    bool ok[n];
    memset(ok,0,n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = i+1; j < n; j++)
      {
        if(a[i]==a[j] && (ok[i]!=1 && ok[j]!=1)){
          ans++;
          ok[i] = 1;
          ok[j] = 1;
          break;
        }
      }
    }
    cout << ans << "\n";
  }
  
}