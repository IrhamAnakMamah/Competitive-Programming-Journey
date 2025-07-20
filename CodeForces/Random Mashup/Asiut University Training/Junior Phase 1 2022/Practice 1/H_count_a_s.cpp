#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    string s;
    cin >> s;

    int a[s.length()];
    for (int i = 0; i < s.length(); i++)
    {
      if(s[i]=='a'){
        a[i] = 1;
      }else{
        a[i] = 0;
      }
    }

    vector<int> pref(s.length()+1, 0);
    for (int i = 1; i <= s.length(); i++)
    {
      pref[i] = a[i-1] + pref[i-1];
    }
        
    int n;
    cin >> n;   
    
    for (int i = 0; i < n; i++)
    {
      int l,r;
      cin >> l >> r;
      int ans = pref[r] - pref[l-1];
      cout << ans << endl;
    }
    
  }
  
}