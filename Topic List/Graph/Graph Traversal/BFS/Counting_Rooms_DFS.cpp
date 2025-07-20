#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

vector<vector<bool>> vis;
int n,m;
char s[1005][1005];

bool cek (int i, int j){
  return i>=0 && i<n && j>=0 && j<m && s[i][j] != '#';
}

void dfs(int a, int b){
  vis[a][b] = 1;
  for (int i = 0; i < 4; i++)
  {
    int x = a + dx[i];
    int y = b + dy[i];
    if(cek(x,y) && !vis[x][y]){
      // cout << x << " " << y << endl;
      dfs(x,y);
    }
  }
}

int main(){
  int ans = 0;
  cin >> n >> m;

  // disini menggunakan vector karena lebih ringan ketimbang menggunakan map
  vis.resize(n+1, vector<bool>(m+1, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> s[i][j];
    }
    
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if(!vis[i][j] && s[i][j] != '#'){
        dfs(i,j);
        ans++;
      }
    }
    
  }
  
  cout << ans << endl;
}