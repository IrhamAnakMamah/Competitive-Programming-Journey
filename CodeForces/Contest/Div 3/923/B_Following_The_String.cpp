#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int n,x;
    cin >> n;
    string ans = "";
    int a[26];
    memset(a,0,sizeof(a));
    for (int i = 0; i < n; i++)
    {
      cin >> x;
      for (int j = 0; j < 26; j++)
      {
        if(a[j]==x){
          ans += (char)('a'+j);
          a[j]=x+1;
          break;
        }
      }
      
    }
    cout << ans << "\n";
    

  }
  
}