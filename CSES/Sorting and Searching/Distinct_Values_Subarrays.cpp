#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  int n;
  cin >> n;

  int a[n];

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  int ans = 0;
  int awal = 0;

  map<int,int> mp;

  for (int i = 0; i < n; i++)
  {
    if(mp.find(a[i]) != mp.end()){
      awal = max(awal,mp[a[i]]+1);a
    } 
    mp[a[i]] = i;
    ans += i-awal+1;
  }
  cout << ans << endl;
}