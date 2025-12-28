#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n,m;
  cin >> n >> m;

  vector<pair<int,int>> a(n);
  vector<int> cache(n);
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;

    a[i] = {x, i};
    cache[i] = x;
  }
  
  if(m > (n/2)){
    cout << -1 << endl;
    return;
  }

  sort(a.begin(), a.end(), greater<>());
  
  vector<pair<int,int>> ans;
  bool ok = 0;
  int i = 0;
  int j = (m == 0 ? 1 : m);
  while (i < n && j < n)
  {
    auto&[x1,y1] = a[i];
    auto&[x2,y2] = a[j];
    
    if(!ok){
      ok = 1;
      ans.push_back({y1 + 1, y2 + 1});
    }else{
      ans.push_back({y2 + 1, y1 + 1});
    }
    x1 -= cache[y2];
    x2 -= cache[y1];
    if(i < m-1){
      ok = 0;
      i++;
      j++;
      continue;
    }
    if(x1 <= 0){
      ok = 0;
      i = j+1;
      j += 2;
    }else{
      j++;
    }
  }
  
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if(a[i].first <= 0){
      cnt++;
    }
  }
  if(cnt == (n-m)){
    cout << ans.size() << endl;
    for(auto [x,y] : ans){
      cout << x << " " << y << endl;
    }
  }else{
    cout << -1 << endl;
  }
  
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