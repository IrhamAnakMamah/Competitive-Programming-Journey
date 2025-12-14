#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,k,q;
  int ans = 1;
  cin >> n >> m >> k >> q;

  set<int> company[k+1];
  vector<bool> station(m+1, 0);
  set<pair<int,int>> adj[n+1];

  station[1] = 1;
  for (int i = 0; i < m; i++)
  {
    int a,b,c;
    cin >> a >> b >> c;
    adj[a].insert({b,c});
    if(a == 1) company[c].insert(b);
  }

  while (q--)
  {
    int xx;
    cin >> xx;
    if(xx == 1){
      int a,b,c;
      cin >> a >> b >> c;
      adj[a].insert({b,c});
      if(station[a] && !station[b]){
        company[c].insert(b);
      }
    }else if(xx == 2){
      int a,b,c;
      cin >> a >> b >> c;
      adj[a].erase({b,c});
      auto idx = company[c].find(b);
      if(idx != company[c].end()){
        company[c].erase(idx);
      }
    }else{
      int c;
      stack<int> st;

      cin >> c;
      for(auto x : company[c]){
        if(!station[x]){
          station[x] = 1;
          ans++;
          st.push(x);
        }
      }

      company[c].clear();
      while (!st.empty())
      {
        for(auto[x,y] : adj[st.top()]){
          if(!station[x]){
            company[y].insert(x);
          }
        }
        st.pop();
      }
      cout << ans << endl;
    }
  }
  
  
}