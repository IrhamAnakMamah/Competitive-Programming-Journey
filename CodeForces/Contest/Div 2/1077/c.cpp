#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll inf = 1e9;

// sorting menurun, swap ai dan aj yang dimana |ai - aj| >= k
void solve(){
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  bool ok = 1;
  for (int i = 1; i < n; i++)
  {
    if(a[i] < a[i-1]) ok = 0;
  }
  
  if(ok){
    cout << -1 << endl;
    return;
  }

  vector<int> t;
  t = a;
  sort(t.begin(), t.end());

  int mn = *min_element(a.begin(), a.end());
  int mx = *max_element(a.begin(), a.end());
  int ans = inf;

  for (int i = 0; i < n; i++)
  {
    if(t[i] == a[i]) continue;
    int x = abs(a[i] - mn);
    int y = abs(a[i] - mx);
    ans = min(ans, max(x, y));
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