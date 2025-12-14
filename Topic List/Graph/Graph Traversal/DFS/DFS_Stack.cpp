/*

  Author  : Iham.
  Tag     : DFS with Stack

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

void dfs(int x){
  stack<int> st;
  vis[x] = 1;
  st.push(x);
  while (!st.empty())
  {
    int u = st.top();
    cout << u << " ";
    st.pop();
    for(auto v : adj[u]){
      if(!vis[v]){
        st.push(v);
        vis[v] = 1;
      }
    }
  }
  
}

int main(){
  int n;
  cin >> n;

  int m;
  cin >> m;

  adj.resize(n+1);

  for (int i = 0; i < m; i++)
  {
    int x,y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  
  vis.resize(n+1);
  for (int i = 1; i <= n; i++)
  {
    if(!vis[i]){
      dfs(i);
      cout << endl;
    }
  }
  
}