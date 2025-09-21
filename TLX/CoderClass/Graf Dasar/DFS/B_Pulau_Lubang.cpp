#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

int n,m;
vector<vector<bool>> vis;
string s[101];

bool checker(int a, int b){
  return a >= 0 && a < n && b >= 0 && b < m && s[a][b] != '#';
}

int dfs(int a, int b){
  int ans = 1;
  vis[a][b] = 1;
  for (int i = 0; i < 4; i++)
  {
    int x = a+dx[i];
    int y = b+dy[i];
    if(checker(x,y)){
      if(!vis[x][y]){
        ans += dfs(x,y);
      }
    }
  }
  return ans;
}

int main(){
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }
  vis.resize(n+1, vector<bool>(m+1, 0));
  int ans = 0;
  int ans1 = 0;
  int k = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if(!vis[i][j] && s[i][j] != '#'){
        k++;
        int temp = dfs(i,j);
        if(temp > ans){
          ans1 = k;
          ans = temp;
        }
      }
    }
    
  }
  cout << k << " " << ans << endl; 
}