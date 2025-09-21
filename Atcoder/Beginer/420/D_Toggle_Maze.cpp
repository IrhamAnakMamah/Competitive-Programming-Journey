#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

int main(){
  int n,m;
  cin >> n >> m;

  string s[n];
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }
  
  vector<vector<int>> vis(n+1, vector<int>(m+1, 0));
  vector<vector<int>> d(n+1, vector<int>(m+1, 0));

  bool ok = 1;
  bool ada = 0;
  
  auto checker = [&] (int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m && s[i][j] != '#' && vis[i][j] < 10;
  };
  
  int sum = 0;
  auto bfs = [&] (int xx, int yy){
    queue<pair<int,int>> q;
    q.push({xx,yy});
    vis[xx][yy]++;
    sum++;
    while (!q.empty())
    {
      bool cek = 0;
      auto[x,y] = q.front();
      cout << x << ' ' << y << endl;
      q.pop();
      for (int i = 0; i < 4; i++)
      {
        vector<pair<int,int>> temp;
        int a = x + dx[i];
        int b = y + dy[i];
        if(checker(a,b)){

          if(vis[a][b] > 1){  
            temp.push_back({a,b});
            continue;
          }

          if(s[a][b] == 'G'){
            ada = 1;
            sum++;
            break;
          }

          if(s[a][b] == '.'){
            cek = 1;
            vis[a][b]++;
            q.push({a,b});
          }else if(s[a][b] == '?'){
            cek = 1;
            ok ^= 1;
            vis[a][b]++;
            q.push({a,b});
          }
          else if(ok){
            if(s[a][b] == 'o'){
              cek = 1;
              vis[a][b]++;
              q.push({a,b});
            }
          }else{
            if(s[a][b] == 'x'){
              cek = 1;
              vis[a][b]++;
              q.push({a,b});
            }
          }
        }
        if(!cek && temp.size() > 0){
          for(auto [aa,bb] : temp){
            q.push({aa,bb});
          }
        }
        sum++;
      }
      if(ada){
        break;
      }
    }
    return sum;
  };
  
  bfs(0,0);
  cout << sum << endl;
}