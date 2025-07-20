#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n]; 
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  map<ll,int> sum;
  ll ans = 0;
  ll pref = 0;

  for (int i = 0; i < n; i++)
  {
    pref+=a[i];
    ans+=sum[pref/n];
  }
  cout << ans << "\n";
}