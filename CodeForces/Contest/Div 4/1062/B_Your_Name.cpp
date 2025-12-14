#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    string s,t;
    cin >> s >> t;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    bool ok = 1;
    for (int i = 0; i < n; i++)
    {
      if(s[i] != t[i]){
        ok = 0;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
  
}
