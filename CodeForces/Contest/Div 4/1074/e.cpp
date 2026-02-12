#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n, m, k;
  cin >> n >> m >> k;

  vector<bool> vis(n, 0);
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  vector<int> b(m);
  for (int i = 0; i < m; i++)
  {
    cin >> b[i];
  }
  
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  map<ll, vector<ll>> mp;
  for (int i = 0; i < n; i++)
  {
    int it = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    if(it == m) it--;
    mp[b[it] - a[i]].push_back(i);
    if(it - 1 >= 0){
      mp[b[it - 1] - a[i]].push_back(i);
    }
  }
  
  string s;
  cin >> s;

  int cnt = 0;
  int ans = n;
  map<ll, bool> vismp;
  for (int i = 0; i < k; i++)
  {
    if(s[i] == 'L'){
      cnt--;
    }else{
      cnt++;
    }

    if(!vismp[cnt]){
      if(mp.find(cnt) != mp.end()){
        for(auto x : mp[cnt]){
          if(!vis[x]){
            vis[x] = 1;
            ans--;
          }
        }
      }
      vismp[cnt] = 1;
    }
    cout << ans << " ";
  }
  cout << endl;
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