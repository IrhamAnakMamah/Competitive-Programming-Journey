#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n,m,k;
  cin >> n >> m >> k;

  ll arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  ll a[m], b[m], d[m];
  for (int i = 0; i < m; i++)
  {
    cin >> a[i] >> b[i] >> d[i];
  }

  vector<ll> cache(m+1, 0);
  vector<ll> pref(n+1, 0);

  for (int i = 0; i < k; i++)
  {
    int x,y;
    cin >> x >> y;
    cache[x-1]++;
    cache[y]--;
  }

  vector<ll> temp(m+2, 0);
  for (int i = 1; i <= m+1; i++)
  {
    temp[i] = temp[i-1] + cache[i-1];
  }

  for (int i = 0; i < m; i++)
  {
    int l = a[i] - 1;
    int r = b[i];
    pref[l] += (temp[i+1] * d[i]);
    pref[r] -= (temp[i+1] * d[i]);
  }
  
  vector<ll> diff(n+2, 0);
  for (int i = 1; i <= n+1; i++)
  {
    diff[i] = diff[i-1] + pref[i-1];
  }
  
  for (int i = 1; i <= n; i++)
  {
    cout << diff[i] + arr[i-1] << " ";
  }
  
  
}