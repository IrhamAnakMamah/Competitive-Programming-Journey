#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  ll n;
  cin >> n;

  ll temp = 1;
  ll cnt = 0;
  while (true)
  {
    if(n - temp <= 0){
      break;
    }else{
      cnt++;
      temp*=2;
    }
  }
  
  ll pw = pow(2,cnt);
  if(pw == n) pw*=2;
  
  pw--;

  ll x = pw & ~(n);
  cout << (x == 0 ? 1 : x) << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
  }
  
}