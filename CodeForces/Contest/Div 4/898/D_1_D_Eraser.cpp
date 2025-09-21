#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,k;
    cin >> n >> k;

    string s;
    cin >> s;

    int ans = 0;
    int counted = 0;
    for (int i = 0; i < n; i++)
    {
      if(!counted){
        if(s[i] == 'B'){
          counted++;
          ans++;
        }
      }else{
        counted++;
      }

      if(counted == k){
        counted = 0;
      }
    }
    cout << ans << endl;
  }
  
}