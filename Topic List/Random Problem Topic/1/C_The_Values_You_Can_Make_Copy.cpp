#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;

  vector<vector<bool>> vis(501, vector<bool>(501, 0));
  vis[0][0] = 1;
  
  vector<vector<int>> cache(501);
  cache[0].push_back(0);

  vector<vector<int>> temp;
  set<int> ans;
  int a[n];

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  for (int i = 0; i <= k; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if(i - a[j] < 0) continue;
      if(vis[i-a[j]][0] && !vis[i-a[j]][j+1]){
        vis[i][0] = 1;
        vis[i][j+1] = 1;
        cache[i] = cache[i-a[j]];
        cache[i].push_back(a[j]);
        if(i == k){
          temp.push_back(cache[i]);
        }
      }
    }
  }

  for(auto x : temp){
    for(auto y : x){
      cout << y << " ";
    }
    cout << endl;
  }
  
  if(temp.size() == 0){
    cout << 0 << endl;
  }else{
    // vector, value, nilai index
    vector<vector<vector<bool>>> vis1(temp.size(), vector<vector<bool>>(501, vector<bool>(501, 0)));

    vector<bool> real(501, 0);
    real[0] = 1;
    for (int i = 0; i < temp.size(); i++)
    {
      vis1[i][0][0] = 1;
    }
    
    for (int i = 0; i <= k; i++)
    {
      for (int j = 0; j < temp.size(); j++)
      {
        for (int x = 0; x < temp[j].size(); x++)
        {
          if(i - temp[j][x] < 0) continue;
          if(vis1[j][i-temp[j][x]][0] && !vis1[j][i-temp[j][x]][x]){
            vis1[j][i][0] = 1;
            vis1[j][i][x+1] = 1;
            real[i] = 1;
          }
        }
        
      }
      
    }

    for (int i = 0; i <= k; i++)
    {
      if(real[i]) ans.insert(i);
    }
    
    cout << ans.size() << endl;
    for(auto x : ans){
      cout << x << " ";
    }
    cout << endl;
  }
}