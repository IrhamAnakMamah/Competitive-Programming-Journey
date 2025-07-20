#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    
    for (int i = 0; i < m; i++)
    {
      cin >> b[i];
    }
    
    sort(b.begin(), b.end());

    a.insert(a.begin(), -100000000);
    bool ok = 1;
    for (int i = 1; i <= n; i++)
    {
      if(a[i] < a[i-1] && b[0] - a[i] < a[i-1]){
        ok = 0;
      }
      a[i] = min((a[i] < a[i-1] ? 1e9 : a[i]), (b[0] - a[i] < a[i-1] ? 1e9 : b[0] - a[i]));
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
  
}