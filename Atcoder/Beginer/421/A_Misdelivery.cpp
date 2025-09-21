#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  string s[n];
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }

  int q;
  string t;
  cin >> q >> t;
  q--;
  cout << (s[q] == t ? "Yes" : "No") << endl;
  
}