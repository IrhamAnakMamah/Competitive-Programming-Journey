#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> ans(n+1, 0);
    vector<int> cache;
    vector<bool> vis(n+1, 0);
    if(n & 1){
      ans[n-1] = 1;
      vis[1] = 1;
      cache.push_back(1);
      if((n-1)&1){
        vis[n-2] = 1;
        ans[n] = n-2;
        cache.push_back(n-2);
      }else{
        vis[n] = 1;
        ans[n] = n;
        cache.push_back(n);
      }
  
      for (int i = n-2; i > 1; i--)
      {
        ans[i] = i ^ 1;
        vis[i^1] = 1;
        cache.push_back(i^1);
      }
      
      bool ok = 0;
      for(auto x : cache){
        int temp = 1 ^ x;
        if((temp > 0 && temp <= n) && !vis[temp]){
          ans[1] = temp;
          ok = 1;
          break;
        }
      }
      
      if(ok){
        for (int i = 1; i <= n; i++)
        {
          cout << ans[i] << " ";
        }
      }else{
        cout << -1;
      }
      cout << endl;
    }else{
      
    }
  }
  
}