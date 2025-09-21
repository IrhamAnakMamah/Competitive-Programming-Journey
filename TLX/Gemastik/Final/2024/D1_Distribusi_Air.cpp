#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class DSU{
  vector<int> p,vis;
  vector<ll> sz;
public:
  DSU(int n){
    p.resize(n+1, 0);
    sz.resize(n+1, 0);
    for (int i = 1; i <= n; i++)
    {
      p[i] = i;
      sz[i] = 1LL;
    }
    
  }

  int find(int u){
    if(u == p[u]){
      return u;
    }else{
      return p[u] = find(p[u]);
    }
  }

  void unite(int u, int v){
    int x = find(u);
    int y = find(v);
    if(x == y) return;
    else if(sz[x] < sz[y]) swap(x,y);
    p[y] = x;
    sz[x] += sz[y];
  }

  ll getSz(int u){
    return sz[find(u)];
  }
};

int main(){
  int n, m, q;
  cin >> n >> m >> q;

  vector<tuple<int,int,int>> edge;
  vector<int> query(q);
  for (int i = 0; i < m; i++)
  {
    int x,y,z;
    cin >> x >> y >> z;
    edge.push_back({x,y,z});
  }
  
  for (int i = 0; i < q; i++)
  {
    char c;
    int a;
    cin >> c >> a;
    a--;
    query[i] = a;
    auto &[x,y,z] = edge[a];
    z = 0;
  }
  
  DSU dsu(n+1);
  ll sum = 0;
  for (int i = 0; i < m; i++)
  {
    auto[x,y,z] = edge[i];
    if(z == 0) continue;
    dsu.unite(x,y);
  }
  
  for (int i = 1; i <= n; i++)
  {
    if(dsu.find(i) == i){
      ll temp = dsu.getSz(i);
      sum += (temp*(temp-1))/2;
    }
  }

  vector<ll>ans;
  for (int i = q-1; i >= 0; i--)
  {
    ans.push_back(sum);

    auto [x,y,z] = edge[query[i]];
    
    int u = dsu.find(x);
    int v = dsu.find(y);
    if(u == v) continue;

    int temp1 = dsu.getSz(u);
    int temp2 = dsu.getSz(v);

    sum -= ((temp1*(temp1-1))/2) + ((temp2*(temp2-1))/2);

    dsu.unite(u,v);

    temp1 = dsu.getSz(dsu.find(u));

    sum += ((temp1*(temp1-1))/2);
  }

  reverse(ans.begin(), ans.end());
  for(auto a : ans){
    cout << a << endl;
  }
}