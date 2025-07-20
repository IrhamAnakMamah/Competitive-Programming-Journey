#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;

  vector<vector<int>> adj(n+1);
  vector<pair<int,int>> a(m+1);

  for (int i = 0; i < m; i++)
  {
    int x,y;
    cin >> x >> y;
    a[i] = {x,y};
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  
  vector<int> ans(n+1);
  vector<bool> vis(n+1,0);
  bool tim = 0;

  auto bfs = [&] (int k){
    queue<int>q;
    q.push(k);
    vis[k] = 1;
    // count gunanya buat mengetahui berapa banyak temen, kayak 1 mempunyai teman 2 dan 3, berarti satu memiliki 2 teman. jadi bool tim bisa berubah ketika temannya sudah habis di queue menggunakan xor, tau habisnya menggunakan count
    int count = 1;
    while (!q.empty())
    {
      int x = q.front();
      q.pop();
      for(auto a : adj[x]){
        if(!vis[a]){
          ans[a] = tim+1;
          vis[a] = 1;
          q.push(a);
        }
      }
      count--;
      if(count == 0){
        count = q.size();
        tim^=1;
      }
    }
    
  };

  for (int i = 1; i <= n; i++)
  {
    if(!vis[i]){
      ans[i] = tim+1;
      tim^=1;
      bfs(i);
    }
  }

  bool boleh = 1;

  //pengecekan apakah antar temen memiliki nilainya yang sama satu sama lain
  for (int i = 0; i < m; i++)
  {
    auto [x,y] = a[i];
    if(ans[x] == ans[y]){
      boleh = 0;
    }
  }
  
  if(boleh){
    for (int i = 1; i <= n; i++)
    {
      cout << ans[i] << " ";
    }
    cout << endl;
  }else{
    cout << "IMPOSSIBLE" << endl;
  }
  
}