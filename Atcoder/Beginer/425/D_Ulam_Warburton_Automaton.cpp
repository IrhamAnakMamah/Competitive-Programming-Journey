#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;

    vector<string> s(n);
    for(int i=0;i<n;i++) cin >> s[i];

    auto inside = [&](int x,int y){ 
      return x>=0 && x<n && y>=0 && y<m; 
    };

    int ans = 0;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
       if(s[i][j] == '#') ans++;
      }  
    } 

    queue<pair<int,int>> q;
    vector<vector<bool>> inq(n, vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j] == '.'){
                int cnt = 0;
                for(int k=0;k<4;k++){
                    int nx = i + dx[k], ny = j + dy[k];
                    if(inside(nx,ny) && s[nx][ny] == '#') cnt++;
                }
                if(cnt == 1){
                    q.push({i,j});
                    inq[i][j] = true;
                }
            }
        }
    }
    while(!q.empty()){
        int sz = q.size();
        vector<pair<int,int>> toFlip;
        for(int t=0; t<sz; t++){
            auto [i,j] = q.front(); q.pop();
            inq[i][j] = false;

            if(s[i][j] == '#') continue;
            int cnt = 0;
            for(int k=0;k<4;k++){
                int nx = i + dx[k], ny = j + dy[k];
                if(inside(nx,ny) && s[nx][ny] == '#') cnt++;
            }
            if(cnt == 1) toFlip.push_back({i,j});
        }

        if(toFlip.empty()) break;

        for(auto [i,j] : toFlip){
            if(s[i][j] == '.'){
                s[i][j] = '#';
                ans++;
            }
        }
        for(auto [i,j] : toFlip){
            for(int k=0;k<4;k++){
                int nx = i + dx[k], ny = j + dy[k];
                if(inside(nx,ny) && s[nx][ny] == '.' && !inq[nx][ny]){
                    q.push({nx,ny});
                    inq[nx][ny] = true;
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
