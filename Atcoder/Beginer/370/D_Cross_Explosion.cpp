#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,q;
  cin >> n >> m >> q;
  vector<vector<bool>> vis(n+1, vector<bool>(m+1, 0));

  for (int i = 0; i < q; i++)
  {
    int x,y;
    cin >> x >> y;
    x--;
    y--;

    if(!vis[x][y]){
      vis[x][y] = 1;
    }else{
      // untuk x
      if(x-1 >= 0 && !vis[x-1][y]){
        vis[x-1][y] = 1;
      }
      if(x+1 < n && !vis[x+1][y]){
        vis[x+1][y] = 1;
      }
      if(y-1 >= 0 && !vis[x][y-1]){
        vis[x][y-1] = 1;
      }
      if(y+1 < m && !vis[x][y+1]){
        vis[x][y+1] = 1;
      }
    }
  }

  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if(vis[i][j]){
        sum++;
      }
    }
  }
  
  cout << (n*m) - sum << endl;
  
}