#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct dsu{
  vector<int> p, edge, node;
  dsu (int n){
    p.resize(n);
    for (int i = 0; i < n; i++)
    {
      p[i] = i;
    }
    edge.resize(n, 0);
    node.resize(n, 1);
  }

  int find(int u){
    if(u == p[u]){
      return u;
    }
    return p[u] = find(p[u]);
  }

  void unite(int u, int v){
    int x = find(u);
    int y = find(v);
    if(x == y) edge[x]++;
    else{
      p[x] = y;
      edge[y] += edge[x] + 1;
      node[y] += node[x];
    }
  }

  int query(int n){
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      if(find(i) == i){
        ans += min(edge[i], node[i]);
      }
    }
    return ans;
  }

};

int main(){
  int n;
  cin >> n;

  vector<pair<int,int>> edges(n+1);
  vector<int> val;

  for (int i = 0; i < n; i++)
  {
    int x,y;
    cin >> x >> y;
    edges[i] = {x-y, x+y};
    val.push_back(x-y);
    val.push_back(x+y);
  }
  
  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());

  int sz = val.size();
  dsu dsu(sz);
  
  for (int i = 0; i < n; i++)
  {
    int u = lower_bound(val.begin(), val.end(), edges[i].first) - val.begin();
    int v = lower_bound(val.begin(), val.end(), edges[i].second) - val.begin();
    // cout << u << " " << v << endl;
    dsu.unite(u,v);
  }
  
  int ans = dsu.query(sz);
  cout << ans << endl;
}