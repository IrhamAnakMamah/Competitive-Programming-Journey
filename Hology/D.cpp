#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    ll n;
    cin >> n;

    vector<ll> cache;
    ll mn = 0;
    for (int i = 0; i < n; i++)
    {
      ll a;
      cin >> a;
      if(mn == 0){
        mn = a;
      }else{
        if(a > mn){
          cache.push_back(a);
        }
        mn = min(mn, a);
      }
    }
    
    if(cache.size() == 0){
      cout << 0 << endl;
    }else{
      sort(cache.begin(), cache.end());
      int med = cache[cache.size() / 2];
      
      int index = 0;
      int l = 0, r = cache.size() - 1;

      while (l <= r) {
        int mid = (l + r) / 2;
        if (cache[mid] <= med) {
          l = mid + 1;
          index = mid;
        } else {
          r = mid - 1;
        }
      }

      ll ans = LLONG_MAX;
      // cout << index << " " << med << " ";
      for (int i = max(index - 1, 0); i <= min(int(cache.size()) - 1, index + 1); i++) {
        ll res = 0;
        for(auto x : cache){
          res += llabs(x - cache[i]);
        }
        ans = min(ans, res);
      }
      cout << ans << endl;
    }
  }
  
}