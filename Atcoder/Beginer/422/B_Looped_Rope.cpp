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
  
  int ok = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int count = 0;
      if(s[i][j] == '#'){
        for (int k = 0; k < 4; k++)
        {
          int x = i + dx[k];
          int y = j + dy[k];
          if(x >= 0 && x < n && y >= 0 && y < m){
            if(s[x][y] == '#'){
              count++;
            }
          }
        }
        if(count == 2 || count == 4){

        }else{
          ok = 0;
        }
      }
    }
    
  }
  cout << (ok ? "Yes" : "No") << endl;
}