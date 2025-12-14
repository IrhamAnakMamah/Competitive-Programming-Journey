#include <bits/stdc++.h>
using namespace std;

int main(){
  int x;
  cin >> x;
  
  int n;
  cin >> n;
  vector<bool> vis(n+1, 0);
  int a[n];

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  int ans = x;
  int q;
  cin >> q;

  while (q--)
  {
    int p;
    cin >> p;
    p--;
    if(!vis[p]){
      ans += a[p];
    }else{
      ans -= a[p];
    }
    vis[p] = vis[p] ^ 1;
    cout << ans << endl;
  }
  
}