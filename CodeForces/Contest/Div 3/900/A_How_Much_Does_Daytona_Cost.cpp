#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,m;
    cin >> n >> m;
    bool ok = 0;
    for (int i = 0; i < n; i++)
    {
      int a;
      cin >> a;
      bool temp = (a==m);
      if(temp){
        ok = 1;
      }
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
  
}