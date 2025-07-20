#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    bool ok = 1;
    cin >> n;
    int x;
    vector<int > a(n+1,0);
    cin >> x;
    a[x]++;
    for (int i = 0; i < n-1; i++)
    {
      cin >> x;
      if((x==1 || (a[x-1]==0)) && (x==n || (a[x+1]==0)))
      ok = 0;
      a[x]++;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  
}