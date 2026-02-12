#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class dsu{
  vector<int> parent, size;
public:
  dsu(int n){
    parent.resize(n+1, 0);
    size.resize(n+1);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int find(int u){
    if(u == parent[u]){
      return u;
    }
    return parent[u] = find(parent[u]);
  }

  void Union(int u, int v){
    int x = find(u);
    int y = find(v);
    if(x == y) return;
    else if(size[x] > size[y]){
      parent[y] = x;
      size[x] += size[y];
    }else{
      parent[x] = y;
      size[y] += size[x];
    }
  }

  int getSize(int u){
    return size[u];
  }
};

struct edge {
  int u, v;
  ll w; 
};

struct query {
  int u, v;
  ll w;
  int id;
};

bool cmpedge(const edge& a, const edge& b) {
  return a.w < b.w;
}

bool cmpquery(const query& a, const query& b) {
  return a.w < b.w;
}

void solve(){
  int n, m;
  cin >> n >> m;

  vector<int> h(n);
  for (int i = 0; i < n; i++)
  {
    cin >> h[i];
  }

  vector<edge> edges;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    u--; v--;
    edges.push_back({u, v, (ll)max(h[u], h[v])});
  }
  
  int q;
  cin >> q;
  vector<query> queri(q);
  for (int i = 0; i < q; i++)
  {
    int a, b, e;
    cin >> a >> b >> e;
    a--; b--;
    queri[i] = {a, b, (ll)h[a] + e, i};
  }

  sort(edges.begin(), edges.end(), cmpedge);
  sort(queri.begin(), queri.end(), cmpquery);

  dsu dsu(n);
  
  vector<string> ans(q);
  int idx_edge = 0;

  for (int i = 0; i < q; i++)
  {
    while(idx_edge < m && edges[idx_edge].w <= queri[i].w){
      dsu.Union(edges[idx_edge].u, edges[idx_edge].v);
      idx_edge++;
    }

    if(dsu.find(queri[i].u) == dsu.find(queri[i].v)){
      ans[queri[i].id] = "YES";
    }else{
      ans[queri[i].id] = "NO";
    }
  }
  
  for (int i = 0; i < q; i++)
  {
    cout << ans[i] << endl;
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