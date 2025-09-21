#include <bits/stdc++.h>
using namespace std;

vector<bool> tim1;
vector<bool> tim2;
vector<vector<int>> edges;
int n,m;

bool dfs(int a, bool note){
  if(note == 0){
    tim1[a] = 1;
  }else{
    tim2[a] = 1;
  }

  for(auto x : edges[a]){
    if(!tim1[x] && !tim2[x]){
      if(note == 0){
        tim2[x] = 1;
        if(!dfs(x,1)){
          return 0;
        }
      }else{
        tim1[x] = 1;
        if(!dfs(x,0)){
          return 0;
        }
      }
    }else if(tim1[x] == tim1[a] || tim2[x] == tim2[a]){
      return 0;
    }
  }
  return 1;
}

int main(){
  cin >> n >> m;
  tim1.resize(n+1, 0);
  tim2.resize(n+1, 0);
  edges.resize(n+1);

  for (int i = 0; i < m; i++)
  {
    int x,y;
    cin >> x >> y;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }
  bool ok = 1;
  for (int i = 1; i <= n; i++)
  {
    if(!tim1[i] && !tim2[i]){
      ok = dfs(i,0);
      if(!ok){
        break;
      }
    }
  }
  cout << (ok ? "YA" : "TIDAK") << endl;
  
}