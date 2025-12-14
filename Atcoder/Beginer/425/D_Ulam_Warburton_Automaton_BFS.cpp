#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void solve(){
  int n,m;
  cin >> n >> m;

  string s[n];
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }
  
  vector<vector<bool>> vis(n+1, vector<bool>(m+1, 0));

  int ans = 0;

  auto cek = [&] (int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
  };

  vector<pair<int,int>> q, que;
  auto bfs = [&] (){
    while (!q.empty())
    {
      que = q;
      q.clear();
      while(!que.empty()){
      
      auto [a,b] = que.front();
      que.pop_back();

      for (int i = 0; i < 4; i++)
      {
        int xx = dx[i] + a;
        int yy = dy[i] + b;

        if(cek(xx,yy) && !vis[xx][yy]){
          int hitam = 0;
          for (int j = 0; j < 4; j++)
          {
            int xxx = dx[j] + xx;
            int yyy = dy[j] + yy;
            if(cek(xxx,yyy)){
              if(s[xxx][yyy] == '#'){
                hitam++;
              }
            }
          }

          if(hitam == 1){
            q.push_back({xx,yy});
            ans++;
            s[xx][yy] = '#';
            vis[xx][yy] = 1;
          }
        }
      }
      
      }
    }
  };

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if(s[i][j] == '#'){
        q.push_back({i,j});
        vis[i][j] = 1;
        ans++;
      }
    }
    
  }
  que = q;
  bfs();
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
  }
  
}