#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    bool ok = 1;
    unordered_map<int,int> mp;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      mp[a[i]]++;
    }
    int k = 1;
    map<int,int> ans;
    // x itu yang ada di a, y itu frekuensi
    for(auto [x,y] : mp){
      if(y%x==0){
        ans[x] = k;
        k++;
      }else{
        ok = 0;
      }
    }
    if(!ok){
      cout << -1 << endl;
    }else{
      map<int,int> count;
      for (int i = 0; i < n; i++)
      {
        count[a[i]]++;
        if(count[a[i]] > a[i]){
          count[a[i]] = 1;
          ans[a[i]] = k;
          k++;
        }
        int x = ans[a[i]];
        cout << x << " "; 
      }
      cout << endl;
    }
  }
  
}