#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<int> cache;

void dfs(int i, int langkah){
  if(langkah == 0){
    cache.push_back(i);
    return;
  }
  for(auto a : edges[i]){
    dfs(a,langkah-1);
  }
}

void solve(){
  
  int n,m,k;
  cin >> n >> m >> k;

  string s;
  cin >> s;

  edges.clear();
  edges.resize(n+1);

  for (int i = 0; i < m; i++)
  {
    int x,y;
    cin >> x >> y;

    edges[x].push_back(y);
  }
  
  cache.clear();
  int bob = 0;
  int alice = 0;

  dfs(1, k*2);
  for(auto a : cache){
    a--;
    if(s[a] == 'A'){
      alice++;
    }else{
      bob++;
    }
  }
  if(alice > bob){
    cout << "Alice" << endl;
  }else{
    cout << "Bob" << endl;
  }
}

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  
}