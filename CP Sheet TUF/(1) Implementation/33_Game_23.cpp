#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n,m,ans = 0;
  cin >> n >> m;
  if(n==m){
    cout << 0 << "\n";
  }else if(m%n!=0){
    cout << -1 << "\n";
  }else{
    ll d = m/n;
    while(d%2==0){
      d/=2;
      ans++;
    }
    while(d%3==0){
      d/=3;
      ans++;
    }
    if(d!=1)ans = -1;
    cout << ans << "\n";
  }
  
}