#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(){
  int n,m;
  cin >> n >> m;
  string s[n];
  pair<int,int> akhir;
  pair<int,int> awal;
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
    for (int j = 0; j < m; j++)
    {
      if(s[i][j] == 'A'){
        akhir = {i,j};
      }else if(s[i][j] == 'B'){
        awal = {i,j};
      }
    }
  }
  
  vector<vector<bool>> vis(n+1, vector<bool>(m+1, 0));
  map<pair<int,int>, pair<int,int>> p;
  p[{awal.first,awal.second}] = {-1,-1};
  
  auto checker = [&] (int a,int b){
    return a >= 0 && a < n && b >= 0 && b < m; 
  };

  auto bfs = [&] (pair<int,int> z){
    queue<pair<int,int>> q;
    auto[xx,yy] = z;
    q.push({xx,yy});
    while(!q.empty()){
      auto[a,b] = q.front();
      // cout << a << " " << b << endl;
      vis[a][b] = 1;
      q.pop();
      for (int i = 0; i < 4; i++)
      {
        int x = dx[i] + a;
        int y = dy[i] + b;
        if(checker(x,y) && !vis[x][y] && s[x][y] != '#'){
          q.push({x,y});
          p[{x,y}] = {a,b};
        }
      }
    }
  };

  bfs(awal);
  auto[a,b] = akhir;
  if(vis[a][b]){
    cout << "YES" << endl;
    auto[c,d] = akhir;
    auto temp = akhir;
    vector<char> ans;
    for (pair<int,int> w = p[{c,d}]; w.first != -1 && w.second != -1; w = p[{w.first,w.second}])
    {
      //first = x, second = y
      if(temp.first < w.first){
        ans.push_back('D');
      }else if(temp.first > w.first){
        ans.push_back('U');
      }else if(temp.second < w.second){
        ans.push_back('R');
      }else{
        ans.push_back('L');
      }
      
      temp = w;
    }
    
    cout << ans.size() << endl;
    for(auto zz : ans){
      cout << zz;
    }
    cout << endl;
  }else{
    cout << "NO" << endl;
  }

}