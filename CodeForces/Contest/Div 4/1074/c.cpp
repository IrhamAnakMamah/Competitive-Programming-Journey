#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  int mn = 1e9+5;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    mn = min(a[i], mn);
  }
  
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());
  
  int ans = 0;
  int sz = (int)a.size();
  for (int i = 0; i < sz; i++)
  {
    vector<int> v;
    v = a;
    for (int j = 0; j < sz; j++)
    {
      v[j] -= a[i];
    }
    
    int cnt = 0;
    for (int j = 0; j < sz; j++)
    {
      if(v[j] == cnt){
        cnt++;
      }
    }
    ans = max(cnt, ans);
  }
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;

  while (t--)
  {
    solve();
  }
  
  return 0;
}