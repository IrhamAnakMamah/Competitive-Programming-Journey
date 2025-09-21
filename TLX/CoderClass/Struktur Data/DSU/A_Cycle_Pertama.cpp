#include <bits/stdc++.h>
using namespace std;

class dsu{
  vector<int> p,sz;
public:
  dsu(int n){
    p.resize(n+1, 0);
    sz.resize(n+1);
    for (int i = 0; i <= n; i++)
    {
      p[i] = i;
      sz[i] = 1;
    }
    
  }

  int find(int u){
    if(p[u] == u){
      return u;
    }
    return p[u] = find(p[u]);
  }

  void unite(int u, int v){
    int x = find(u);
    int y = find(v);
    if(x == y) return;
    if(sz[x] < sz[y]) swap(x,y);
    // >
    p[y] = x;
    sz[x] += sz[y];
  }

};

int main(){
  int n,q;
  cin >> n >> q;

  dsu dsu(n);
  int ans = -1;
  for (int i = 1; i <= q; i++)
  {
    int x,y;
    cin >> x >> y;
    if((dsu.find(x) == dsu.find(y)) && ans == -1){
      ans = i;
    }
    dsu.unite(x,y);
  }
  cout << ans << endl;

}