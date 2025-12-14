#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll n;
  cin >> n;

  int a[n];
  vector<ll> freq(n+1, 0);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    freq[a[i]]++;
  }
  
  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    if(freq[i] > 1){
      ans += (n - freq[i]) * ((freq[i] * (freq[i]-1))/2);
    }
  }
  cout << ans << endl;
}