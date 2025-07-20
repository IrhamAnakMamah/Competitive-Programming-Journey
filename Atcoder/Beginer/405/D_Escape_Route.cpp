#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(){
  int n,m;
  cin >> n >> m;

  string s[n];
  queue<pair<int,int>> a;
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
    for (int j = 0; j < s[i].length(); j++)
    {
      if(s[i][j]=='E'){
        a.emplace(i,j);
      }
    }
  }
  
  string cek = "^<v>";
  auto ok = [&](int i, int j){
    return i>=0 && i<n && j>=0 && j<m;
  };

  while (!a.empty())
  {
    auto[x,y] = a.front();
    a.pop();
    for (int i = 0; i < 4; i++)
    {
      int b = x + dx[i];
      int c = y + dy[i];
      if(!ok(b,c)){
        continue;
      }else if(s[b][c] != '.'){
        continue;
      }

      s[b][c] = cek[i];
      a.emplace(b,c);
    }
    
  }
  for (int i = 0; i < n; i++)
  {
    cout << s[i] << endl;
  }
  
}