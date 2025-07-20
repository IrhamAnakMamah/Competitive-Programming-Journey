#include <bits/stdc++.h>
using namespace std;

int dx [] = {-1,0,1,0};
int dy [] = {0,1,0,-1};
  
int n,m;
  
bool vis[105][105];
vector<vector<int>> dist;
vector<vector<int>> s;
  
vector<pair<int,int>> ans;

bool ujung(int i,int j){
  return (i==0 || j==0 || i==n-1 || j==m-1) && s[i][j] != -1;
}

bool cek(int i, int j){
  return i>=0 && i<n && j>=0 && j<m && s[i][j] != -1;
}

void bfs (int i, int j){
    queue<pair<int,int>> q;
    q.emplace(i,j);
    vis[i][j] = 1;
    // cout << "TES" << endl;
    while(!q.empty()){
      auto [a,b] = q.front();
      q.pop();
      for (int k = 0; k < 4; k++)
      {
        int c = a + dx[k];
        int d = b + dy[k];
        // cout << c << " " << d << endl;
        if(!vis[c][d] && cek(c,d)){
          if(ujung(c,d)){
            ans.push_back({c,d});
            dist[c][d] = dist[a][b] + 2;
          }else{
            dist[c][d] = dist[a][b] + 1;
          }
          vis[c][d] = 1;
          q.emplace(c,d);
        }
      }
      
    }
}

int main(){
  cin >> n >> m;

  s.resize(n+1, vector<int>(m+1, 0));
  dist.resize(n+1, vector<int>(m+1, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> s[i][j];
    }
    
  }
  

  int x,y;
  cin >> x >> y;
  x--;
  y--;
  
  // jika berada pada titik ujung layaknya i == 0 atau i == n dan begitu pula dengan j. maka itu berada pada pintu keluar. tidak diketahui berapa pintu keluar yang tersedia

  if(ujung(x,y)){
    ans.push_back({x,y});
    dist[x][y]++;
  }else{
    bfs(x,y);
  }
  int mn = INT_MAX;
  for(auto [a,b] : ans){
    mn = min(mn, dist[a][b]);
  }
  cout << mn << endl;
}