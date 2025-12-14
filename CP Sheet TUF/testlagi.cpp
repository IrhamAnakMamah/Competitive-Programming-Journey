#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<bool> vis(n+1, 0);
    
    for (int i = 0; i < n-1; i++)
    {
      if(i == 0){
        if(s[i] == 'L' && s[n-1] == 'R'){
          vis[i] = 1;
          vis[n-1] = 1;
        }else if(s[i] == 'R' && s[i+1] == 'L'){
          vis[i] = 1;
          vis[i+1] = 1;
        }
      }else if(s[i] == 'R' && s[i+1] == 'L' && (!vis[i] && !vis[i+1])){
        vis[i] = 1;
        vis[i+1] = 1;
      }
    }
    
    vector<pair<char,int>> cache;
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
      if(!vis[i] && !vis[i-1] && s[i] == s[i-1]){
        if(!cnt){
          cnt = 2;
        }else{
          cnt++;
        }
      }
      else if(i == 0 && !vis[0]){
        cache.push_back({s[i], 1});
      }else{
        if(cnt){
          cache.push_back({s[i-1], cnt});
          cnt = 0;
        }
      }
    }
    
    if(cnt || !vis[n-1] && s[n-1] == s[0] && !vis[0]){
      if(cache.size() == 0){
        cache.push_back({s[n-1], cnt});
      }else{
        cache[0].second += (cnt == 0 ? 1 : cnt);
      }
    }else if(cnt > 0){
      cache.push_back({s[n-1], cnt});
    }

    int ans = 0;
    if(cache.size() == 1){
      ans += ((cache[0].second-1)/3) + 1;
    }else{
      for(auto [_, x] : cache){
        x-=2;
        ans += ((x)/3) + 1;
      }
    }
    cout << ans << endl;
  }
  
}