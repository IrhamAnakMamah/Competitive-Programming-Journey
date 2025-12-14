#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int a[n+1];
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  
  ll ans = 0;
  vector<int> vis(n+1, 0);
  for (int i = 1; i <= n; i++)
  {
    if(!vis[i]){
      // cout << i << endl;
      ll cycle = 0;
      ll cur = i;

      while (!vis[cur])
      {
        vis[cur] = 1;
        cur = a[cur];
        cycle++;
      }
      
      ans += (cycle * (cycle - 1)) / 2;
    }
  }
  cout << ans << endl;
  return 0;
}