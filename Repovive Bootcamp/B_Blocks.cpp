#include <bits/stdc++.h>
using namespace std;

// bisa putih atau hitam

int main(){
  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<int> cache;
  string temp = s;
  for (int i = 0; i < n; i++)
  {
    if(temp[i] == 'B' && i != n-1){
      temp[i] = 'W';
      temp[i+1] = (temp[i+1] == 'B' ? 'W' : 'B');
      cache.push_back(i+1);
    }
  }
  
  bool ok = 1;
  for (int i = 0; i < n; i++)
  {
    if(temp[i] != 'W'){
      ok = 0;
      break;
    }
  }
  
  if(ok){
    vector<int> ans;
    ans = cache;
    cout << ans.size() << endl;
    for(auto x : ans){
      cout << x << " ";
    }
    cout << endl;
    return 0;
  }
  cache.clear();

  temp = s;
  for (int i = 0; i < n; i++)
  {
    if(temp[i] == 'W' && i != n-1){
      temp[i] = 'B';
      temp[i+1] = (temp[i+1] == 'B' ? 'W' : 'B');
      cache.push_back(i+1);
    }
  }

  ok = 1;
  for (int i = 0; i < n; i++)
  {
    if(temp[i] != 'B'){
      ok = 0;
      break;
    }
  }
  
  if(ok){
    vector<int> ans;
    ans = cache;
    cout << ans.size() << endl;
    for(auto x : ans){
      cout << x << " ";
    }
    cout << endl;
  }else{
    cout << -1 << endl;
  }
  
}