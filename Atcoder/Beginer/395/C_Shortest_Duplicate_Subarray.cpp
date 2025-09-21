#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  map<int,int> mp;
  int a[n];

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  int ans = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    if(mp.find(a[i]) == mp.end()){
      mp[a[i]] = i;
    }else{
      ans = min(ans, i - mp[a[i]] + 1);
      mp[a[i]] = i;
    }
  }
  if(ans == INT_MAX){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }
}