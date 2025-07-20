#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll n;
  cin >> n;
  vector<array<ll,2>> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i][0] >> a[i][1];
  }
  sort(a.begin(),a.end());
  ll temp = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans+=a[i][1]-(a[i][0]+temp);
    temp+=a[i][0];
  }
  cout << ans << "\n";
}