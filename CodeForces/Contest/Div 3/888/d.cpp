#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  ll n;
  cin >> n;

  ll a[n];
  for (int i = 0; i < n-1; i++)
  {
    cin >> a[i];
  }
  
  vector<ll> sum(n);
  vector<bool> cache(2e5 + 5, 0);

  for (int i = 0; i < n-1; i++)
  {
    if(i == 0) sum[i] = a[i];
    else sum[i] = a[i] - a[i-1];
  }
  
  if(a[n-2] != (n * (n + 1))/2){
    a[n-1] = (n * (n + 1))/2;
    sum[n-1] = a[n-1] - a[n-2];
    bool ok = 1;
    sort(sum.begin(), sum.end());
    for (int i = 0; i < n; i++)
    {
      if(sum[i] != i+1) ok = 0;
    }
    
    cout << (ok ? "Yes" : "No") << endl;
  }else{
    vector<ll> hilang;
    for (int i = 0; i < n-1; i++)
    {
      if(sum[i] <= n && !cache[sum[i]]){
        cache[sum[i]] = 1;
      }else{
        hilang.push_back(sum[i]);
      }
    }
    
    vector<ll> ada;
    for (int i = 1; i <= n; i++)
    {
      if(!cache[i]){
        cache[i] = 1;
        ada.push_back(i);
      }
    }
    
    if(hilang.size() != 1 || ada.size() != 2){
      cout << "No" << endl;
    }else{
      cout << (ada[0] + ada[1] == hilang[0] ? "Yes" : "No") << endl;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;

  while (t--)
  {
    solve();
  }
  
  return 0;
}
