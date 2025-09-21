#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
const ll MOD = 998244353;

class dsu{
  public:
  vector<int> parent, sz;

  dsu(int n){
    parent.resize(n+1, 0);
    sz.resize(n+1, 0);
    for (int i = 1; i <= n; i++)
    {
      parent[i] = i;
      sz[i] = 1;
    }
  }

  int find(int u){
    if(parent[u] == u){
      return u;
    }
    return parent[u] = find(parent[u]);
  }

  void unite(int a, int b){
    int x = find(a);
    int y = find(b);
    if(x == y) return;
    if(sz[x] < sz[y]) swap(x,y);
    parent[y] = x;
    sz[x] += sz[y];
  }

};

int main(){
  int n;
  cin >> n;

  ll u[n], v[n], w[n];
  for (int i = 0; i < n-1; i++)
  {
    cin >> u[i] >> v[i] >> w[i];
  }
  vector<ll> cache(max(n+1, 31), 1);
  for (int i = 1; i <= max(n, 30); i++)
  {
    cache[i] = (cache[i-1] * 2) % MOD;
  }

  ll total = cache[n];
  ll ans = 0;
  for (int k = 0; k <= 30; k++)
  {
    dsu dsu(n);
    for (int i = 0; i < n-1; i++)
    {
      if(((w[i] >> k) & 1) == 0){
        dsu.unite(u[i], v[i]);
      }
    }
    
    ll sum = 0;
    ll comp = 0;
    for (int i = 1; i <= n; i++)
    {
      if(dsu.find(i) == i){
        // cout << k << " " << i << endl;
        sum = (sum + cache[dsu.sz[i]]) % MOD;
        comp++;
      }
    }
    
    ll countZero = (sum - (comp - 1) + MOD) % MOD;
    ll countSet = ((total - countZero) + MOD) % MOD;
    ans = (ans + countSet * cache[k]) % MOD;
  }
  cout << ans << endl;
}