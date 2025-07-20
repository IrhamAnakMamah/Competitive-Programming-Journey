#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> div(n*2+1,0);
    vector<pair<int,int>> cache;
    for (int i = 0; i < n; i++)
    {
      int l,r;
      cin >> l >> r;
      if(l==r){
        div[l-1]++;
      }
      cache.push_back({l,r});
    }
    vector<int> ans(n,-1);

    for (int i = 0; i < n; i++)
    {
      auto [x,y] = cache[i];
      if(x==y){
        ans[i] = (div[x-1] == 1 ? 1 : 0);
      }
    }

    for (int i = 0; i < n; i++)
    {
      auto [x,y] = cache[i];
      if(x==y){
        div[x-1] = 1;
      }
    }

    vector<int> pref(n*2+2,0);

    for (int i = 1; i <= n*2+1; i++)
    {
      pref[i] = pref[i-1] + div[i-1];
    }
    
    for (int i = 0; i < n; i++)
    {
      if(ans[i]!=-1){
        cout << ans[i];
      }else{
        auto [x,y] = cache[i];
        if((y-x+1)-(pref[y]-pref[x-1])>0){
          cout << 1;
        }else{
          cout << 0;
        }
      }
    }
    cout << endl;
  }
  
}
