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
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    ll sum = 0, mn = 0;
    for (int i = 0; i < n; i++)
    {
      sum+=a[i];
      mn = min (mn,sum);
    }
    ll ans = sum - 2*mn;
    cout << ans << "\n";
  }
  
}