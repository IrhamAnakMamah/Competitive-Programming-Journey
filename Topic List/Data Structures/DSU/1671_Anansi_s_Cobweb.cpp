#include <bits/stdc++.h>
using namespace std;

int jumlah = 0;

class dsu{
  vector<int> parent,size;
public:
  dsu(int n){
    parent.resize(n+1,0);
    size.resize(n+1);
    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
      size[i] = 1;
    }
    jumlah = n;
  }

  int find(int u){
    if(u == parent[u]){
      return u;
    }
    return parent[u] = find(parent[u]);
  }

  void merge(int u, int v){
    int x = find(u);
    int y = find(v);
    if(x == y) return;
    jumlah--;
    if(size[x] > size[y]){
      parent[y] = x;
      size[x] += size[y];
    }else{
      parent[x] = y;
      size[y] += size[x];
    }
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m;
  cin >> n >> m;
  dsu d(n);

  vector<pair<int,int>> edges;
  for (int i = 0; i < m; i++)
  {
    int x,y;
    cin >> x >> y;
    edges.push_back({x,y});
  }

  int q;
  cin >> q;
  vector<int> query(q);
  for (int i = 0; i < q; i++)
  {
    int a;
    cin >> a;
    query[i] = a;
  }
  
  vector<bool> boleh(q, 1);
  for (int i = 0; i < q; i++)
  {
    boleh[--query[i]] = 0;
  }

  for (int i = 0; i < m; i++)
  {
    if(boleh[i]){
      d.merge(edges[i].first, edges[i].second);
    }
  }

  vector<int> ans(q+1);
  for (int i = 0; i < q; i++)
  {
    ans[i] = jumlah;
    auto[x,y]  = edges[query[i]];
    d.merge(x,y);
  }
  
  reverse(ans.begin(), ans.end());
  for(auto x : ans){
    if(x != 0){
      cout << x << (x == ans.back() ? "\n" : " ");
    }
  }
  
}