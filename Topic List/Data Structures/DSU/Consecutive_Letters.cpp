#include <bits/stdc++.h>
using namespace std;

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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  int k = 1;
  while (t--)
  {
    string s;
    cin >> s;

    int q;
    cin >> q;

    int n = (int)s.length();
    dsu dsu(n);
    vector<pair<int,char>> query;

    for (int i = 0; i < q; i++)
    {
      int x,y;
      cin >> x >> y;
      if(x == 1){
        query.push_back({y,'0'});
      }else{
        query.push_back({y,s[y]});
        s[y] = '#';
      }
    }

    for (int i = 0; i < n-1; i++)
    {
      if(s[i] == '#') continue;
      if(s[i] == s[i+1]){
        dsu.Union(i,i+1);
      }
    }
    vector<int> res;
    for (int i = q-1; i >= 0; i--)
    {
      auto[x,y] = query[i];
      if(y == '0'){
        int ans = dsu.find(x);
        // cout << ans << endl;
        res.push_back(dsu.getSize(ans));
      }else{
        s[x] = y;
        if(x+1 < n && s[x] == s[x+1]){
          dsu.Union(x,x+1);
        }
        if(x-1 >= 0 && s[x] == s[x-1]){
          dsu.Union(x,x-1);
        }
      }
    }
    reverse(res.begin(), res.end());
    cout << "Case " << k << ":" << '\n';
    k++;
    for(auto x : res){
      cout << x << '\n'; 
    }
  }
  
}