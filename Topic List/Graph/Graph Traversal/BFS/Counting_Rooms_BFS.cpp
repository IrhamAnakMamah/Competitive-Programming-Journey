#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(){
  int n,m;
  int ans = 0;
  cin >> n >> m;

  string s[n];
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }
  
  vector<vector<bool>> vis(n+1, vector<bool>(m+1, 0));
  queue<pair<int,int>> q;
  
  auto cek = [&] (int i,int j){
    return i>=0 && i<n && j>=0 && j<m && s[i][j] != '#';
  };

  auto bfs = [&] (int xx, int yy){
    q.emplace(xx,yy);
    vis[xx][yy] = 1;
    while (!q.empty())
    {
      auto[a,b] = q.front();
      q.pop();
      for (int i = 0; i < 4; i++)
      {
        int x = a + dx[i];
        int y = b + dy[i];
        if(cek(x,y) && !vis[x][y]){
          vis[x][y] = 1;
          q.emplace(x,y);
        }
      }
      
    }
    
  };

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if(!vis[i][j] && s[i][j] != '#'){
        bfs(i,j);
        ans++;
      }
    }
    
  }
  
  cout << ans << endl;
}