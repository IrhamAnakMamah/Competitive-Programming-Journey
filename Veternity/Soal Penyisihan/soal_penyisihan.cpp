#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>> adj(n+1);
  vector<bool> towerUtama(n+1, 0);
  vector<int> nilaiTowerUtama;
  for (int i = 1; i <= n; i++)
  {
    int a;
    cin >> a;
    towerUtama[i] = a;
    if(a){
      nilaiTowerUtama.push_back(i);
    }
  }
  
  for (int i = 0; i < m; i++)
  {
    int x,y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  vector<bool> vis(n+1, 0);
  bool cek = 0;
  auto bfs = [&] (int i){
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    int temp = i;
    while (!q.empty())
    {
      int x = q.front();
      q.pop();
      if(towerUtama[x]){
        cek = 1;
      }
      for(auto a : adj[x]){
        if(!vis[a]){
          temp = min({temp,a,x});
          vis[a] = 1;
          q.push(a);
        }
      }
    }
    return temp;
  };
  
  vector<int> cache;
  for(int i = 1; i<=n; i++){
    cek = 0;
    if(!vis[i]){
      int bil = bfs(i);
      if(!cek){
        cache.push_back(bil);
      }
    }
  }

  vector<pair<int,int>> ans;
  for(int x : cache){
    auto it = lower_bound(nilaiTowerUtama.begin(), nilaiTowerUtama.end(), x);
    int towerTerdekat;
    if (it == nilaiTowerUtama.end()) {
      towerTerdekat = *prev(it);
    } else if (it == nilaiTowerUtama.begin()) {
      towerTerdekat = *it;
    } else {
      int tower1 = *it;
      int tower2 = *prev(it);
      if (abs(x - tower1) < abs(x - tower2)) {
        towerTerdekat = tower1;
      } else if (abs(x - tower2) < abs(x - tower1)) {
        towerTerdekat = tower2;
      } else {
        towerTerdekat = min(tower1, tower2);
      }
    }
    ans.push_back({x, towerTerdekat});
  }
  
  cout << ans.size() << endl;
  for(auto [x,y] : ans){
    cout << x << " " << y << endl;
  }
  cout << endl;
}