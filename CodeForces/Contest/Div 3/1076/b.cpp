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

  int l = -1;
  int r = -1;
  int mx = 0;
  bool ok = 0;
  for (int i = 1; i < n; i++)
  {
    if(a[i] > a[i-1]){
      ok = 1;
    }

    if(ok && mx < a[i]){
      mx = a[i];
      r = i;
    }
  }

  
  if(!ok){
    for (int i = 0; i < n; i++)
    {
      cout << a[i] << " ";
    }
  }else{
    for (int i = 0; i < r; i++)
    {
      if(mx > a[i]){
        l = i;
        break;
      }
    }
    for (int i = 0; i < l; i++)
    {
      cout << a[i] << " ";
    }
    for (int i = r; i >= l; i--)
    {
      cout << a[i] << " ";
    }
    for (int i = r+1; i < n; i++)
    {
      cout << a[i] << " ";
    }
    
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