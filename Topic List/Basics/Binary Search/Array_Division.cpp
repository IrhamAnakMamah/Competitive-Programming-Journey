#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int n;
int k;

vector<ll> a;

bool f(ll mx){
  ll count = 0;
  ll sum = 0;

  for(auto x : a){
    if(x > mx) return false;

    if(sum + x > mx){
      count++;
      sum = 0;
    }
    sum+=x;
  }
  if(sum > 0) count++;

  return k>=count;
}

int main(){
  cin >> n >> k;

  ll l = 0;
  ll r = 0;

  for (int i = 0; i < n; i++)
  {
    ll x;
    cin >> x;
    a.push_back(x);
    l = max(x,l);
    r+=x;
  }

  while (l<r)
  {
    ll mid = l+(r-l)/2;
    if(f(mid)){
      r = mid;
    }else{
      l = mid+1;
    }
  }

  cout << l << endl;
  
}