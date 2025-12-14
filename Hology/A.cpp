#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int ans = 0;
  int temp = 0;
  map<int,int> mp;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    mp[a]++;
  }
  
  int bilangan = 0;
  int ok = 0;
  for(auto [x,y] : mp){
    if(bilangan == 0){
      ans += (x*y);
    }else if(bilangan+1 == x){
      if(ok == 2){
        ans += (x*y);
        temp += (x*y);
        if(max(ans,temp) == ans){
          temp -= (x*y);
          ok = 0;
        }else{
          ans -= (x*y);
          ok = 1;
        }
      }else if(ok == 1){
        ans += (x*y);
        ok = 0;
      }else{
        temp += (x*y);
        ok = 1;
      }
    }else{
      ok = 2;
      ans += (x*y);
      temp += (x*y);
    }
    bilangan = x;
  }
  
  cout << max(ans, temp) << endl;
  
}