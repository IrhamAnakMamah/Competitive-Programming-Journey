#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;

  int a[n];
  vector<bool> vis(100, 0);
  for (int i = n-1; i >= 0; i--)
  {
    if(i == n-1){
      a[i] = 1;
      vis[1] = 1;
    }else{
      int temp = (i+1) + a[i+1];
      if(!vis[temp] && temp <= n){
        vis[temp] = 1;
        a[i] = temp;
      }else{
        temp = abs(a[i + 1] - (i + 1));
        vis[temp] = 1;
        a[i] = temp;
      }
    }
  }
  
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
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