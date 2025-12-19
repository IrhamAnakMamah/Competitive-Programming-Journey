#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int ans[MAXN];
vector<vector<int>> edges;
vector<int> col;

int main(){
  int n,m;
  cin >> n >> m;
  edges.resize(n+1);
  col.resize(n+1, 0);

  for (int i = 0; i < m; i++)
  {
    int x,y;
    cin >> x >> y;
    edges[x].push_back(y);
    col[y]++;
  }
  
  queue<int> q;
  for (int i = 1; i <= n; i++)
  {
    if(col[i] == 0){
      q.push(i);
    }
  }
  
  vector<int> a;
  bool ok = 1;
  while (!q.empty())
  {
    if(q.size() > 1){
      ok = 0;
      break;
    }

    int u = q.front();
    a.push_back(u);
    q.pop();

    for(auto v : edges[u]){
      col[v]--;
      if(col[v] == 0){
        q.push(v);
      }
    }
  }

  if(ok){
    cout << "Yes" << endl;
    int temp = 1;
    for(auto x : a){
      ans[x] = temp;
      temp++;
    }
    for (int i = 1; i <= n; i++)
    {
      cout << ans[i] << " ";
    }
    cout << endl;
  }else{
    cout << "No" << endl;
  }
}