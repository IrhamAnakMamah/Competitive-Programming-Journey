#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  ll n;
  cin >> n;
  
  queue<pair<ll,ll>> q;

  for (int i = 0; i < n; i++)
  {
    int k;
    cin >> k;
    if(k == 1){
      ll a,b;
      cin >> a >> b;
      q.emplace(a,b);
    }else{
      ll a;
      cin >> a;
      ll sum = 0;
      auto x = q.front();
      while (a != 0)
      {
        if(a <= x.first){
          sum += a * x.second;
          if(a == x.first){
            q.pop();
          }else{
            q.front().first -= a;
          }
          a = 0;
        }else if(a > x.first){
          sum += x.first * x.second;
          a -= x.first;
          q.pop();
          x = q.front();
        }
      }
      cout << sum << endl;
    }
  }
  
}