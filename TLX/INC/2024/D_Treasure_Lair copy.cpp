#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll n,m;
  cin >> n >> m;

  vector<pair<int,int>> cache;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      char c;
      cin >> c;
      if(c == '1'){
        cache.push_back({i,j});
      }
    }
  }
  
  int q;
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    ll a,b,c;
    cin >> a >> b >> c;
    a--;
    b--;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(auto [x,y] : cache){
      int temp = abs(x-a);
      int temp1 = abs(y-b);
      pq.push(((temp - min(temp1,temp))*2 + (temp1 - min(temp1,temp))*2) + (min(temp,temp1) * 2));
    }

    ll ans = 0;
    while (c--)
    {
      ll x = pq.top();
      pq.pop();
      ans += x;
    }
    cout << ans << endl;
  }
  

}