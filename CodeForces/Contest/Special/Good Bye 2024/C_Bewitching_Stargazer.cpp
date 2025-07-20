#include <bits/stdc++.h>
#define ll long long
using namespace std;

pair<ll,int> f(ll l,ll r,int k){
  if(r-l+1<k){
    return {0,0};
  }

  if(r-l+1==1){
    return {l,1};
  }

  ll mid = l + (r-l) /2;

  ll luck = 0;
  int seg = 0;
  
  if((r-l+1)&1){
    pair<ll,int>res = f(l,mid-1,k);
    auto[x,y] = res;
    luck = mid + (2 * x) + (mid * y);
    seg = 2*y+1;
  }else{
    pair<ll,int>res = f(l,mid,k);
    auto[x,y] = res;
    luck = (2 * x) + (mid * y);
    seg = 2*y; 
  }
  return {luck,seg};
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
    ll n,k;
    cin >> n >> k;
    
    pair<ll,int> ans;
    ans = f(1,n,k);
    cout << ans.first << endl;
  }
  
}