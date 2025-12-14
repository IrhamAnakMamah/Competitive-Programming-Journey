#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  string s;
  cin >> s;

  for (int i = 0; i < max(0, n - (int)s.length()); i++)
  {
    cout << "o";
  }
  cout << s << endl;
  
  return 0;
}