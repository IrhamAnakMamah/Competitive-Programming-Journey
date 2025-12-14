#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MINIM = -1 * 1e18;
ll n;
ll w[501], a[501], b[501];
vector<vector<ll>> dp;

ll f(ll idx, ll head, ll body){
  if(idx == n){
    if(head > body){
      return MINIM;
    }else{
      return 0;
    }
  }

  ll temp = 0;
  temp = max(0LL, a[idx] + f(idx+1,head + w[idx], body));
  temp = max(temp, b[idx] + f(idx+1,head, body + w[idx]));
  
  return temp;
}

int main(){
  cin >> n;

  dp.resize(n+1, vector<ll>(2, -1));

  for (int i = 0; i < n; i++)
  {
    cin >> w[i] >> a[i] >> b[i];
  }
  
  ll ans = f(0,0,0);
  cout << ans << endl;
}