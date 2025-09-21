#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
vector<vector<int>> adj;
vector<int> vis;

bool ok = 0;

bool dfs(int i){
  vis[i] = 1;
  for(auto x : adj[i]){
    if(!vis[x]){
      if(dfs(x)){
        return true;
      }
    }else if(vis[x] == 1){
      return true;
    }
  }
  vis[i] = 2;
  ans.push_back(i);
  return false;
}

bool comp(vector<int>& b, vector<int>& c){
  return b.front() < c.front();
}

int main(){
  int n, m;
  cin >> n >> m;
  adj.resize(n+1);
  vis.resize(n+1, 0);
  vector<vector<int>> a;
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
  }
  
  for (int i = 1; i <= n; i++)
  {
    if(!vis[i]){
      ans.clear();
      ok = dfs(i);
      // reverse(ans.begin(), ans.end());
      // cout << endl;
      a.push_back(ans);
      if(ok){
        break;
      }
    }
  }
  if(ok){
    cout << "Sandro fails." << endl;
    return 0;
  }
  // reverse(a.begin(), a.end());
  // sort(a.begin(), a.end(), comp);
  // cout << a.size() << endl;
  for(int i = 0; i<a.size(); i++){
    for(auto x : a[i]){
      cout << x << " ";
    }
  }
  cout << endl;
}