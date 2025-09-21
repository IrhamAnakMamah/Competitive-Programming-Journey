#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,k;
    cin >> n >> k;

    int a[n];
    map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      mp[a[i]]++;
    }
    
    bool ok = 1;
    for(auto [x,y] : mp){
      if(y%k!=0)ok = 0;
    }

    if(!ok){
      cout << 0 << endl;
    }else{
      ll l = 0;
      ll ans = 0;
      map<int,int> cache;
      for (ll i = 0; i < n; i++)
      {
        if(cache[a[i]] != (mp[a[i]]/k)){
          ans += ((i-l)+1);
          cache[a[i]]++;
        }else{
          while (l < i && (cache[a[i]] == (mp[a[i]]/k)))
          {
            cache[a[l]]--;
            l++;
          }
          ans += ((i-l)+1);
          cache[a[i]]++;
        }
      }
      cout << ans << endl;
    }
  }
  
}