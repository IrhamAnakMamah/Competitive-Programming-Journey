#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

bool ok = 0;
ll n,m;
vector<vector<pair<ll,ll>>> edges;
vector<ll> cache;

void dfs(ll x){
  for(auto [a,b] : edges[x]){
    ll temp = cache[x] + b;
    if(cache[a] < temp){
      cache[a] = temp;
      dfs(a);
    }
  }
}

int main(){
  cin >> n >> m;
  edges.resize(n+1);
  cache.resize(n+1, -1);
  cache[1] = 0;
  for (int i = 0; i < m; i++)
  { 
    int x,y,z;
    cin >> x >> y >> z;
    edges[x].push_back({y,z});
  }
  
  dfs(1);
  cout << cache[n] << endl;
}