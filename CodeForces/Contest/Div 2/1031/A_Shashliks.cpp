#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int k,a,b,x,y;
    cin >> k >> a >> b >> x >> y;

    int ans = 0;
    if(k < a && k < b){
      ans = 0;
    }else if(x > y){
      int temp = k-b;
      if(temp < 0){

      }else{
        ans = (temp/y)+1;
        k -= (ans * y);
      }
      if(k >= a){
        temp = k - a;
        ans += (temp/x)+1;
        k-= (ans * x);
      }
    }else{
      int temp = k-a;
      if(temp < 0){
        
      }else{
        ans = (temp/x)+1;
        k -= (ans * x);
      }
      if(k >= b){
        temp = k - b;
        ans += (temp/y)+1;
        k-= (ans * y);
      }
    }
    cout << ans << endl;
  }
  
}