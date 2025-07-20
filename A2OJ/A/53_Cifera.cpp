#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll k,l;
  cin >> k >> l;
  ll temp = l;
  ll ans = 0;
  bool ok = 0;
  while(temp%k==0){
    if(temp==k){
      ok = 1;
      break;
    }
    temp /=k;
    ans++;
  }
  if(ok){
    cout << "YES\n";
    cout << ans << "\n";
  }else{
    cout << "NO\n";
  }
}