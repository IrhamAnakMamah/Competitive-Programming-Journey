#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int main(){
  ll n,k;
  cin >> n >> k;
 
  ll x,a,b,c;
  cin >> x >> a >> b >> c;
 
  vector<ll>cache(n);
  vector<ll>ans;
 
  cache[0] = x;
  for (int i = 1; i < n; i++)
  {
    cache[i] = ((a * cache[i-1]) + b) % c;
  }
 
  ll cnt = 0;
  multiset<int> s;
  for (int i = 0; i < n; i++)
  {
    if(cnt < k){
      cnt++;
      s.insert(cache[i]);
      if(cnt == k){
        ans.push_back(*s.begin());
      }
    }else{
      s.erase(cache[i-k]);
      s.insert(cache[i]);
      ans.push_back(*s.begin());
    }
  }
  
  int j = 0;
  ll sum = 0;
  for(auto xx : ans){
    if(j == 0){
      sum = xx;
      j++;
    }else{
      sum ^= xx;
    }
  }
  cout << sum << endl;
}