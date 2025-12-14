#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool op(pair<ll,ll> &a, pair<ll,ll> &b){
  if(a.first == b.first){
    return a.second < b.second;
  }
  return a.first < b.first;
}

int main(){
  int n;
  cin >> n;

  vector<pair<ll,ll>> ans;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;

    ll b[a];
    ll c[a];
    for (int j = 0; j < a; j++)
    {
      cin >> b[j];
    }

    for (int j = 0; j < a; j++)
    {
      cin >> c[j];
      c[j] = c[j] % b[j];
    }
    
    ll l = 1;
    bool overflow = false;

    for (int j = 0; j < a; j++)
    {
      if (c[j] == 0) continue; 
      if (overflow) continue;
      ll temp = b[j] / __gcd(b[j], c[j]);
      ll fpb_gabungan = __gcd(l, temp);
      __int128 cek_hasil = (__int128)l / fpb_gabungan * temp;

      if (cek_hasil > 2e18) {
          l = 2e18 + 7;
          overflow = true;
      } else {
          l = (ll)cek_hasil;
      }
    }
    ans.push_back({l, i+1});
  }
  
  sort(ans.begin(), ans.end(), op);
  int j = 0;
  for(auto [_, x] : ans){
    if(j == 3) break;
    cout << x << " ";
    j++;
  }
  cout << endl;
}