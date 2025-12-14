#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    int a[n+1];
    map<int,int> mp;
    int idx = n-1;
    bool ok = 1;
    for (int i = 1; i <= n; i++)
    {
      int x = idx;
      if(i - x < 1){
        x -= (i);
        x = (n - x);
        mp[x]++;
        a[x] = i;
      }else{
        x = (i - x);
        mp[x]++;
        a[x] = i;
      }
      if(mp[x] > 1){
        ok = 0;
        break;
      } 
      idx--;
    }
    
    if(!ok){
      cout << -1 << endl;
    }else{
      for (int i = 1; i <= n; i++)
      {
        cout << a[i] << " ";
      }
      cout << endl;
    }
  }
  
}