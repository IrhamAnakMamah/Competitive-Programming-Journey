#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  vector<bool> vis1(n+1, 0), vis2(n+1, 0);
  bool ok = 0;
  for (int i = 0; i < n; i++)
  {
    if(ok){
      vis1[i] = 1;
      continue;
    }
    if(a[i] == 1){
      ok = 1;
      vis1[i] = 1;
    }
  }
  ok = 0;
  for (int i = n-1; i >= 0; i--)
  {
    if(ok){
      vis2[i] = 1;
      continue;
    }
    if(a[i] == 1){
      ok = 1;
      vis2[i] = 1;
    }
  }
  
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans += (vis1[i] && vis2[i]);
  }
  cout << ans-(ans>0) << endl;
}