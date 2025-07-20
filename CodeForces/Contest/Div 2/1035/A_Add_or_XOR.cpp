#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    ll a,b,x,y;
    ll ans = 0;
    cin >> a >> b >> x >> y;
    if(a>b && (b&1 || abs(a-b)>=2)){
      cout << -1 << endl;
    }else if(a > b){
      a--;
      if(a == b){
        cout << y << endl;
      }else{
        cout << -1 << endl;
      }
    }else{
      ll mn = min(x,y);
      ll mx = max(x,y);
      if(mn == y && mn != mx){
        while(a!=b){
          if(a&1){
            ans+=x;
            a++;
          }else{
            ans+=y;
            a++;
          }
        }
      }else{
        ans = (b-a) * x; 
      }
      cout << ans << endl;
    }
  }
  
}