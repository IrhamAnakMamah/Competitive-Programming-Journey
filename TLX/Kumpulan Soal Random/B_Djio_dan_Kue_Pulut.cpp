#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll n;
  cin >> n;
  ll sum = 0;
  vector<ll> a(n);
  for(auto &x : a){
    cin >> x;
    sum+=x;
  }
  ll ans = 0;
  sort(a.begin(), a.end(), greater<>());
  if(a[0]>(sum/2)){
    ans = (2*a[0])-1;
  }else{
    ans = sum;
  }

  cout << ans << "\n";
}