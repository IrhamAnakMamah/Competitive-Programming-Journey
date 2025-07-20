#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll t,n;
  char c;
  ll ans = 0;
  cin >> t;
  bool ok = 0;
  while (t--)
  {
    cin >> c >> n;
    if(c=='P'){
      ans-=n;
    }else{
      ans+=n;
      if(ans>0){
        cout << "YES" << endl;
        ans = 0;
      }else{
        cout << "NO" << endl;
      }
    }
  }
  
}