#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,x,y;
  cin >> n >> m >> x >> y;

  // 2 = y, 1 = x
  vector<pair<int,int>> cache(m+1);
  for(int i = 0; i < m; i++)
  {
    int c,d;
    cin >> c >> d;
    cache[i] = {c,d};
  }
  
  
  int ans = 0;
  int kode = -1;
  int mx = 0;

  for (int i = 0; i < m; i++)
  {
    auto [c,d] = cache[i];
    if(i == 0){
      kode = c;
      if(kode == 1){
        mx = abs(d - x);
        ans += abs(d - x);
        x = d;
      }else{
        mx = abs(d - y);
        ans += abs(d - y);
        y = d;
      }
    }else{
      if(kode == c){
        int temp = abs(d - (kode == 1 ? x : y));
        mx += temp;
        ans += temp;
        if(c == 1){
          x = d;
        }else{
          y = d;
        }
      }else{
        if(c == 1){
          if(mx < abs(d - x)){
            ans += (abs(d - x) - mx);
          }
          x = d;
        }else{
          if(mx < abs(d - y)){
            ans+= (abs(d - y) - mx);
          }
          y = d;
        }
        mx = 0;
        kode = c;
      }
    }
  }
  cout << ans << endl;
  
}