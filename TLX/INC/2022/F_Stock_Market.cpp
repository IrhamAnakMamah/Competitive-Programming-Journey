#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll n,p,x;
  cin >> n >> p >> x;

  ll a[n];

  ll sum = 0;
  for (ll i = 0; i < n; i++)
  {
    cin >> a[i];
    sum += a[i];
  }

  ll ans = INT_MAX;
  ll sumAll = p;
  for (ll i = 0; i < n; i++)
  {
    ll temp = sumAll;
    ll y = abs(x - sumAll)/(sum * -1);
    temp += (y * sum);
    if(temp < ans && temp >= x){
      ans = temp;
    }
    sumAll += a[i];
  }
  
  cout << (ans == INT_MAX ? -1 : ans) << endl;
  
}