#include <bits/stdc++.h>
using namespace std;

class dsu{
  vector<int> parent, size;
public:
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
    if(parent[u] == u){
      return u;
    }
    return find(parent[u]);
  }

  bool ask(int u, int v){
    int x = find(u);
    int y = find(v);
    if(x == y){
      return 1;
    }else{
      return 0;
    }
  }

  void cut(int u, int v){
    int x = find(u);
    int y = find(v);
    cout << "TEST" << endl;
    if(x==y){
      parent[v] = v;
    }
  }

  void insert(int u, int v){
    if(u > v){
      parent[u] = v;
    }else{
      parent[v] = u;
    }
  }
};

int main(){
  int n,m,k;
  cin >> n >> m >> k;

  dsu dsu(n+1);

  for (int i = 0; i < n; i++)
  {
    int x,y;
    cin >> x >> y;
    dsu.insert(x,y);
  }
  
  for (int i = 0; i < k; i++)
  {
    string s;
    int x,y;
    cin >> s >> x >> y;
    if(s == "ask"){
      bool cek = dsu.ask(x,y);
      if(cek){
        cout << "YES" << endl;
      }else{
        cout << "NO" << endl;
      }
    }else{
      dsu.cut(x,y);
    }
  }
  
}