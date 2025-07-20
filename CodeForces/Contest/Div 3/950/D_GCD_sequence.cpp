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
    int b[n-1];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
      b[i-1] = __gcd(a[i],a[i-1]);
    }
    int ans = 0;
    for (int i = 0; i < n-1; i++)
    {
      // if(b[i]<b[i-1])ans++;
      cout << b[i] << " ";
    }
    cout << endl;
    // cout << (ans>1 ? "NO" : "YES") << endl;
  }
  
}