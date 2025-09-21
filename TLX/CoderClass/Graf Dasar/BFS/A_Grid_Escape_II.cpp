#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(){
  int n,m;
  cin >> n >> m;

  string s[n];
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
    
  }
  
  queue<pair<int,int>> q;
  vector<vector<bool>> vis(n+1, vector<bool>(m+1, 0));
  vector<vector<int>> a(n+1, vector<int>(m+1, 0));

  auto checker = [&] (int i, int j){
    return (i >= 0 && j >= 0) && (i < n && j < m) && s[i][j] != '#';
  };

  auto bfs = [&] (int xx, int yy){
    q.emplace(xx,yy);
    vis[xx][yy] = 1;
    while (!q.empty())
    {
      auto[x,y] = q.front();
      q.pop();
      for (int i = 0; i < 4; i++)
      {
        int temp1 = x + dx[i];
        int temp2 = y + dy[i];
        if(checker(temp1, temp2)){
          if(!vis[temp1][temp2]){
            vis[temp1][temp2] = 1;
            a[temp1][temp2] += a[x][y] + 1;
            q.emplace(temp1,temp2);
          }
        }
      }
    }
    
  };

  bfs(0,0);
  cout << (a[n-1][m-1] == 0 ? -1 : a[n-1][m-1]) << endl;
}