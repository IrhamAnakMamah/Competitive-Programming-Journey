#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,k;
  cin >> n >> m >> k;

  string s[n];
  string t[n];

  map<string,bool> mp;
  for (int i = 0; i < n; i++)
  {
    cin >> s[i] >> t[i];
    if(i < m){
      mp[t[i]] = 1;
    }
  }
  
  vector<string> ans;
  for (int i = m; i < n; i++)
  {
    if(mp.find(t[i]) == mp.end()){
      ans.push_back(s[i]);
      mp[t[i]] = 1;
      k--;
    }

    if(k == 0){
      break;
    }
  }
  cout << ans.size() << endl;
  for(auto x : ans){
    cout << x << endl;
  }
  
}