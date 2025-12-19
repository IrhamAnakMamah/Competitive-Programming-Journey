#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

int main(){
  int n, m;
  cin >> n >> m;

  string s[n];
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }

  vector<vector<bool>> vis(n+1, vector<bool>(m+1, 0));
  int ans = 0;

  auto cek = [&] (int u, int v){
    return u >= 0 && u < n && v >= 0 && v < m && s[u][v] != '#' && !vis[u][v];
  };

  auto bfs = [&] (int u, int v){
    queue<pair<int,int>> q;
    q.push({u,v});
    vis[u][v] = 1;
    while (!q.empty())
    {
      auto [a,b] = q.front();
      q.pop();
      for (int i = 0; i < 4; i++)
      {
        int x = a + dx[i];
        int y = b + dy[i];
        if(cek(x,y)){
          vis[x][y] = 1;
          q.push({x,y});
        }
      }
      
    }
    
  };

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if(!vis[i][j] && s[i][j] == '.'){
        bfs(i,j);
        ans++;
      }
    }
    
  }
  cout << ans << endl;
}