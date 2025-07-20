#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n,x;
  cin >> n >> x;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  map<ll,int> sum;
  ll pref = 0;
  ll ans = 0;
  sum[0] = 1;
  for (int i = 0; i < n; i++)
  {
    pref+=a[i];
    ans+=sum[pref-x];
    sum[pref]++;
  }
  cout << ans << "\n";
  
}