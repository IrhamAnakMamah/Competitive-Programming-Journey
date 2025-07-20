#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};


//idenya mencari terlebih dahulu kemungkinan dimana hanya ada 1 jalan yang tersedia, baru gunakan bfs
//jikalau ada jalan yang terbuka sebanyak 3 kali berurutan atau lebih dan sehabis terputus tidak ada lagi jalan yang terbuka, maka taro X disana

int main(){
  int n,m,k;
  bool selesai = 0;
  ll ans = 0;
  cin >> n >> m >> k;

  string s[n];
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }
  
  auto checker = [&](int i, int j){
    return i < 0 || i>= n || j < 0 || j >= m || s[i][j] == '#' || s[i][j] == 'X';
  };
  
  auto bfs = [&](int xx,int yy){
    queue<pair<int,int>> q;
    vector<vector<bool>> vis(n+1,vector<bool>(m+1,0));
    q.emplace(xx,yy);
    while(!q.empty()){
      auto[a,b] = q.front();
      q.pop();
      if(!vis[xx][yy]){
        vis[a][b] = 1;
        int count = 0;
        bool ok = 0;
        for (int k = 0; k < 8; k++)
        {
          int x = a+dx[k];
          int y = b+dy[k];
          if(checker(x,y) && ok == 0){
            count += checker(x,y);
          }else if(ok == 1 && count == 0 && checker(x,y)){
            ok = 0;
            break;
          }else if(checker(x,y)){
            count++;
          }else{
            count = 0;
          }
          if(count >= 3){
            ok = 1;
          }
        }
        if(count == 3){
          s[a][b] = 'X';
          ans++;
        }
        if(ans == k){
          selesai = 1;
          break;
        }
      }
    }
  };

  for (int i = 0; i < n; i++)
  {
    if(selesai){
      break;
    }
    for (int j = 0; j < m; j++)
    {
      if(selesai){
        break;
      }
      int count = 0;
      int ok = 0;
      for (int k = 0; k < 8; k++)
      {
        //tambahin kalo semisal checker bernilai 1
        int x = i+dx[k];
        int y = j+dy[k];
        if(checker(x,y) && ok == 0){
          count += checker(x,y);
        }else if(ok == 1 && count == 0 && checker(x,y)){
          ok = 0;
          break;
        }else if(checker(x,y)){
            count++;
          }else{
            count = 0;
          }
        if(count >= 3){
          ok = 1;
        }
      }
      if(ok){
        s[i][j] = 'X';
        ans++;
        if(ans == k){
          selesai = 1;
          break;
        }else{
          for (int k = 0; k < 8; k++)
          {
            int x = i+dx[k];
            int y = j+dy[k];
            if(checker(x,y)){
              continue;
            }else{
              bfs(x,y);
            }
          }
        }

      }
    } 
  }
  
  for(string z : s){
    cout << s << endl;
  }
}