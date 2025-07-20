#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  string t;
  cin >> t;
  int st = 0;
  int nl = 0;
  for (int i = 0; i < n+m; i++)
  {
    (t[i]=='0' ? nl++ : st++);
  }
  
  cout << (nl == n && st == m ? 1 : 2) << "\n";
}