#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  ll n, m, h;
  cin >> n >> m >> h;

  vector<ll> d(n+1, 0);
  vector<ll> a(n);
  vector<ll> t;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  t = a;
  
  ll cnt = 0;
  while (m--)
  {
    ll b, c;
    cin >> b >> c;
    b--;

    if(d[b] != cnt){
      d[b] = cnt;
      t[b] = a[b];
    }

    t[b] += c;
    if(t[b] > h){
      cnt++;
      t[b] = a[b];
    }
  }
  
  for (int i = 0; i < n; i++)
  {
    if(d[i] != cnt){
      cout << a[i] << " ";
    }else{
      cout << t[i] << " ";
    }
  }
  cout << endl;
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