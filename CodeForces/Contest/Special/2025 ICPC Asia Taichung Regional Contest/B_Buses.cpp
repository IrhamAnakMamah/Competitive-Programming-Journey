#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

// kasus 1 : kalo y > x, langsung pake y saja, tidak usah menggunakan x.
// kasus 2 : kalo y < x, maka akan ada perhitungan dengan y.
// kita ngga bisa ngejar bus jikalau y < x, dan jika x < y, tidak usah mengejar bus

int main(){
  ll n,m,l,x,y;
  cin >> n >> m >> l >> x >> y;

  vector<pair<ll,ll>> st(n);
  for (int i = 0; i < n; i++)
  {
    cin >> st[i].first >> st[i].second;
  }
  
  sort(st.begin(), st.end());

  ll p[m];
  for (int i = 0; i < m; i++)
  {
    cin >> p[i];
  }
  
  if(y >= x){
    for (int i = 0; i < m; i++)
    {
      ld ans;
      ld dist = l - p[i];
      ans = (dist/(y*1.0));
      cout << ans << endl;
    }
  }else{

  }
}