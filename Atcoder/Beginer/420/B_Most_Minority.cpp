#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  string s[n];
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }

  vector<pair<int,int>> cache;
  for (int i = 0; i <= n; i++)
  {
    cache.push_back({0,i});
  }
  
  for (int i = 0; i < m; i++)
  {
    int satu = 0;
    int nol = 0;
    for (int k = 0; k < n; k++)
    {
      satu += (s[k][i] == '1');
      nol += (s[k][i] == '0');
    }
    
    bool ok = 1;
    if(satu > nol){
      ok = 0;
    }

    for (int k = 0; k < n; k++)
    {
      if(ok){
        if(s[k][i] == '1'){
          auto[x,y] = cache[k+1];
          x++;
          cache[k+1] = {x,y};
        }
      }else{
        if(s[k][i] == '0'){
          auto[x,y] = cache[k+1];
          x++;
          cache[k+1] = {x,y};
        }
      }
    }
    
  }

  sort(cache.begin(), cache.end(), greater<>());
  int temp = cache[0].first;
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    if(temp == cache[i].first){
      ans.push_back(cache[i].second);
    }
  }
  sort(ans.begin(), ans.end());
  for(auto pp : ans){
    cout << pp << " ";
  }
  cout << endl;
  
}