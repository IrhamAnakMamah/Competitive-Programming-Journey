#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    string s;
    cin >> n >> s;

    bool ok = 0;

    vector<int> cache(27, 0);
    cache[s[0] - 'a']++;
    cache[s[n-1] - 'a']++;
    for (int i = 1; i < n-1; i++)
    {
      cache[s[i]-'a']++;
      if(cache[s[i]-'a'] > 1){
        ok = 1;
      }
    }
    cout << (ok ? "Yes" : "No") << endl;
  }
  
}