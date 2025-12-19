#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;

  int a[n];
  int b[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }

  vector<int> cnt(n+1, 0);

  vector<pair<ll, int>> d(n);
  for (int i = 0; i < n; i++)
  {
    d[i] = {a[i] - b[i], i+1};
  }
  
  sort(d.begin(), d.end());
  // for (int i = 0; i < n; i++)
  // {
  //   auto [x,y] = d[i];
  //   cout << x << " " << y << endl;
  // }
  
  vector<int> ans;
  for (int i = n-1; i >= 0; i--)
  {
    if(i == n-1){
      ans.push_back(d[i].second);
    }else if(d[i].first == d[i+1].first){
      ans.push_back(d[i].second);
    }else{
      break;
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for(auto x : ans){
    cout << x << " ";
  }
  cout << endl;
}

int main()
{
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