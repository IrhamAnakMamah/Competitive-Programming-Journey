#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;

  string s;
  cin >> s;

  vector<string> cache;
  vector<int> cnt;
  for (int i = 0; i < n-k+1; i++)
  {
    if(i == 0){
      cache.push_back(s.substr(i,k));
      cnt.push_back(1);
    }else{
      string temp = s.substr(i,k);
      bool ok = 0;
      for(int j = 0; j < (int)cache.size(); j++){
        if(cache[j] == temp){
          cnt[j]++;
          ok = 1;
        }
      }
      if(!ok){
        cache.push_back(temp);
        cnt.push_back(1);
      }
    }
  }
  
  int mx = 0;
  for (int i = 0; i < (int)cache.size(); i++)
  {
    mx = max(mx, cnt[i]);
  }
  
  vector<string> ans;
  for (int i = 0; i < (int)cache.size(); i++)
  {
    if(cnt[i] == mx){
      ans.push_back(cache[i]);
    }
  }
  sort(ans.begin(), ans.end());
  cout << mx << endl;
  for(auto x : ans){
    cout << x << " ";
  }
  cout << endl;
}