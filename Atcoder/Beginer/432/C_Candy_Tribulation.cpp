#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll n,x,y;
  cin >> n >> x >> y;

  ll mn = INT_MAX;
  ll mx = 0;

  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    mn = min(a[i], mn);
    mx = max(a[i], mx);
  }
  
  if(mn * y < mx * x){
    cout << -1 << endl;
  }else{
    
  }
}