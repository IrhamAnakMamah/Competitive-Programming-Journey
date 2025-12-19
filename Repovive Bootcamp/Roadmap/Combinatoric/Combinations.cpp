#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<vector<int>> ans;

void f(int j, vector<int>& cache){
  if(cache.size() == k){
    ans.push_back(cache);
  }else{
    for (int i = j+1; i <= n; i++)
    {
      cache.push_back(i);
      f(i, cache);
      cache.pop_back();
    }
  }
}

int main(){
  cin >> n >> k;
  
  vector<int> cache;
  for (int i = 1; i <= n; i++)
  {
    cache.push_back(i);
    f(i, cache);
    cache.pop_back();
  }
  
  cout << "[";
  for (int i = 0; i < ans.size(); i++)
  {
    cout << "[";
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << (j == ans[j].size() - 1 ? "" : ",");
    }
    cout << "]" << (i == ans.size()-1 ? "" : ",");
  }
  cout << "]" << endl;
  
}