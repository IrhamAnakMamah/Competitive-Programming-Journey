#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,m;
    string s;
    cin >> n >> m;
    cin >> s;
    vector<int> a(7,0);
    for (int i = 0; i < n; i++)
    {
      a[s[i]-'A']++;
    }
    int ans = 0;
    for (int i = 0; i < 7; i++)
    {
      ans += max(0,m-a[i]);
    }
    cout << ans << endl;
  }
  
}