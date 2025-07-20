#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    ll a[n];
    ll sum = 0;
    ll mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      sum+=a[i];
      mn = min(mn,a[i]);
    }
    cout << sum - (n*mn) << endl;
  }
  
}
