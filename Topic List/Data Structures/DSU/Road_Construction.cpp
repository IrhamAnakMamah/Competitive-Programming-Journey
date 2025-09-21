#include <bits/stdc++.h>
using namespace std;

class dsu{
  vector<int> parent,size;
public:
  dsu(int n){
    parent.resize(n+1);
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

  int unite(int u, int v){
    int max = -1;
    int x = find(u);
    int y = find(v);
    if(x == y) return -1;
    else if(size[x] < size[y]){
      parent[x] = y;
      size[y] += size[x];
      max = size[y];
    }else{
      parent[y] = x;
      size[x] += size[y];
      max = size[x];
    }
    return max;
  }
};

int main(){
  int n,m;
  cin >> n >> m;

  dsu dsu(n);

  int ans1 = n;
  int ans2 = 1;

  for (int i = 0; i < m; i++)
  {
    int x,y;
    cin >> x >> y;
    int temp = dsu.unite(x,y);
    if(temp != -1){
      ans2 = max(ans2, temp);
      ans1--;
    }
    cout << ans1 << " " << ans2 << endl;
  }
  
}