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
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    sort(a,a+n);

    for (int i = 1; i < n; i+=2)
    {
      mx = max(mx, abs(a[i] - a[i-1]));
    }
    cout << mx << endl;
  }
  
}