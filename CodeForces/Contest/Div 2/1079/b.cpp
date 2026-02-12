#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;

  vector<int> p(n);
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> p[i];
  }
  
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  vector<int> pos(n+1, 0);
  for (int i = 0; i < n; i++)
  {
    pos[p[i]] = (i + 1);
  }
  
  bool ok = 1;
  for (int i = 1; i < (int)a.size(); i++)
  {
    if(pos[a[i]] < pos[a[i-1]]){
      ok = 0;
    }
  }
  
  cout << (ok ? "Yes" : "No") << endl;
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
  
}