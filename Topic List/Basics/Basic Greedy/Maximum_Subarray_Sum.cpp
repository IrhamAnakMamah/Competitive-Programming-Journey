#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin >> n;
  ll a[n];
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  ll ans = a[0];
  ll temp = a[0];

  for (int i = 1; i < n; i++)
  {
    temp = max(temp+a[i],a[i]);
    ans = max(ans,temp);
  }
  cout << ans << "\n";
}