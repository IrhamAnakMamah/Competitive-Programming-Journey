#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;
  
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  vector<pair<int,bool>> v1;
  vector<pair<int,bool>> v2;
  for (int i = 0; i < n; i++)
  {
    v1.push_back({a[i], i&1});
    v2.push_back({a[i], (i+1)&1});
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  bool ok = 1;
  for (int i = 1; i < n; i++)
  {
    if(v1[i].second == v1[i-1].second){
      ok = 0;
      break;
    }
  }
  
  if(ok){
    cout << "YES" << endl;
    return;
  }
  
  ok = 1;
  for (int i = 1; i < n; i++)
  {
    if(v2[i].second == v2[i-1].second){
      ok = 0;
      break;
    }
  }
  cout << (ok ? "YES" : "NO") << endl;
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