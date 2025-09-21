#include <bits/stdc++.h>
using namespace std;

int n;

class dsu{
  vector<int> parent, size;
public:
  dsu (int n){
    parent.resize(n+1);
    size.resize(n+1);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = -1;
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
    // v itu akhir
    int x = find(u);
    int y = find(v);
    parent[x] = y;
  }
  
  int cek(int u){
    int ans = 0;
    int temp = u;
    if(parent[u] != -1){
      temp = find(u);
      temp++;
      if(temp > n){
        temp = 1;
      }
      ans = temp;
      parent[temp] = temp;
      unite(temp - 1 == 0 ? n : temp-1, temp);
      
    }else{
      parent[temp] = u;
      ans = u;
    }
    int temp1 = temp+1;
    if(temp1 > n){
      temp1 = 1;
    }
    if(parent[temp1] != -1){
      unite(temp, temp1);
    }
    int temp2 = temp - 1;
    if(temp2 == 0){
      temp2 = n;
    }
    if(parent[temp2] != -1){
      unite(temp2, temp);
    }
    return ans;
  }

};

int main(){
  cin >> n;

  dsu dsu(n+1);

  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;

    int ans = dsu.cek(a);
    cout << ans << " ";
  }
  cout << endl;
}