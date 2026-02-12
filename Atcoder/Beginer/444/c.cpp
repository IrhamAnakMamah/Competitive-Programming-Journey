#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  ll max_val = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum += a[i];
    max_val = max(max_val, a[i]);
  }

  sort(a.begin(), a.end());

  vector<ll> ans;

  for (ll i = 1; i * i <= sum; i++)
  {
    if (sum % i == 0) {
      vector<ll> cache;
      cache.push_back(i);
      if (i * i != sum) cache.push_back(sum / i);

      for (ll k : cache) {
        if (k >= (n + 1) / 2 && k <= n) {
          ll L = sum / k;
          
          if (L >= max_val) {
            bool possible = true;
            int l = 0;
            int r = n - 1;
            
            while (l <= r) {
              if (a[r] == L) {
                r--;
              } else {
                if (l < r && a[r] + a[l] == L) {
                  r--;
                  l++;
                } else {
                  possible = false;
                  break; 
                }
              }
            }
            if (possible) {
              ans.push_back(L);
            }
          }
        }
      }
    }
  }

  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
  }
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
  }
  
}