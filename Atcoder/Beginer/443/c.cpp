#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n, t;
  cin >> n >> t;

  int ans = 0;
  int time = 0;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  for (int i = 0; i < n; i++)
  {
    if(time < a[i]){
      ans += (a[i] - time);
      time = a[i] + 100;
    }
  }
  
  if(time < t){
    ans += (t - time);
  }
  cout << ans << endl;
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
  
  return 0;
}
