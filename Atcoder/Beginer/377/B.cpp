#include <bits/stdc++.h>
using namespace std;

int main(){
  string s[8];
  vector<pair<int,int>> index;
  for (int i = 0; i < 8; i++)
  {
    cin >> s[i];
  }
  
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if(s[i][j]=='#'){
        index.push_back({i,j});
      }
    }
  }
  
  for(auto a : index){
    for (int i = 0; i < 8; i++)
    {
      s[a.first][i] = '#';
    }
    for (int i = 0; i < 8; i++)
    {
      s[i][a.second] = '#';
    }
  }

  int ans = 0;
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if(s[i][j] == '.'){
        ans++;
      }
    }
    
  }
  cout << ans << "\n";
}