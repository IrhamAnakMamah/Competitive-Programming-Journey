#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    int n,ans = 0;
    cin >> n;
    string s;
    cin >> s;

    vector<int> a(27,0);
    for (int i = 0; i < s.length(); i++)
    {
      a[s[i]-'A']++;
    }
    sort(a.begin(),a.end(), greater<int>());
    
    if(a[2]==0){
      cout << -1 << endl;
    }else{
      ans = a[2]*3;
      for (int i = 0; i < 2; i++)
      {
        ans += (a[i]-a[2]==0 ? 0 : 1);
      }
      cout << ans << endl;
    }
  }
  
}