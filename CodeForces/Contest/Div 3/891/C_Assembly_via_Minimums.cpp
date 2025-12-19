#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin >> n;

  int sz = (n * (n-1))/2;
  int a[sz];
  vector<pair<int,int>> cache;
  set<int> s;
  for (int i = 0; i < sz; i++)
  {
    cin >> a[i];
    s.insert(a[i]);
  }
  
  for(auto x : s){
    int cnt = 0;
    for (int i = 0; i < sz; i++)
    {
      if(a[i] == x){
        cnt++;
      }
    }
    cache.push_back({x, cnt});
  }

  vector<int> b(n+1, INT_MAX);

  for(auto [x,y] : cache){
    int temp = (n - y - 1);
    if(temp >= 0){
      if(b[temp] == INT_MAX){
        b[temp] = x;
      }else{
        int cnt = y;
        for (int i = 0; i < n; i++)
        {
          if(b[i] != INT_MAX){
            continue;
          }else{
            if((n - i - 1) >= 0){
              cnt -= (n - i - 1);
            }
            b[i] = x;
            if(cnt == 0) break;
          }
        }
      }
    }else{
      int cnt = y;
      for (int i = 0; i < n; i++)
      {
        if(b[i] != INT_MAX){
          continue;
        }else{
          if((n - i - 1) >= 0){
            cnt -= (n - i - 1);
          }
          b[i] = x;
          if(cnt == 0) break;
        }
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    if(b[i] == INT_MAX){
      b[i] = b[i-1];
    }
  }
  
  for (int i = 0; i < n; i++)
  {
    cout << b[i] << " ";
  }
  
  cout << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve();
  }
  
  return 0;
}