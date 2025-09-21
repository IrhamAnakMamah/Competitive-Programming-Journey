#include <bits/stdc++.h>
using namespace std;

class dsu{
  vector<int> parent,size;
public : 
  dsu(int n){
    parent.resize(n+1,0);
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

  void unite(int u, int v){
    int x = find(u);
    int y = find(v);
    if(x == y) return;
    else if(size[x] < size[y]){
      parent[x] = y;
      size[y] += size[x];
    }else{
      parent[y] = x;
      size[x] += size[y];
    }
  }
};

int main(){
  int n,q;
  cin >> n >> q;
  
  dsu dsu(n+1);

  for (int i = 0; i < q; i++)
  {
    int a,x,y;
    cin >> a >> x >> y;
    if(a == 0){
      dsu.unite(x,y);
    }else{
      int u = dsu.find(x);
      int v = dsu.find(y);
      if(u!=v){
        cout << 0 << endl;
      }else{
        cout << 1 << endl;
      }
    }
  }
  
  
}