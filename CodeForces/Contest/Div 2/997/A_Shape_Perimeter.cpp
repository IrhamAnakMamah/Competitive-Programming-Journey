#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  cin >> t;
  while (t--)
  {
    int n,m;
    cin >> n >> m;

    int ans = 0;
    int a[n];
    int b[n];
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i] >> b[i];
      sum1+=a[i];
      sum2+=b[i];
    }

    ans = 2*((sum1+m-a[0])+(sum2+m-b[0]));
    cout << ans << endl;
  }
  
}