#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  string a,b;
  cin >> a >> b;
  bool ok = 0;
  for (int i = 0; i < n; i++)
  {
    if((a[i] == b[i]) && (a[i] == 'o')){
      ok = 1;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
}