#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll n,k;
  cin >> n >> k;

  vector<ll> genap;
  for (int i = 0; i < n; i++)
  {
    ll a;
    cin >> a;
    if(a % 2 == 0){
      genap.push_back(a);
    }
  }
  
  ll temp = 0;
  ll ans = 0;
  for (int i = 0; i < genap.size(); i++)
  {
    if(i < 2){
      ans++;
      temp += genap[i];
    }else{
      if(temp <= (genap[i] * k)){
        ans++;
      }
      temp += genap[i];
      temp -= genap[i-2];
    }
  }
  
  cout << ans << endl;
}