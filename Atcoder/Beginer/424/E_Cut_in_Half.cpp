#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using ll = long long;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,k,x;
    cin >> n >> k >> x;

    priority_queue<pair<ld,ll>> pq;
    for (int i = 0; i < n; i++)
    {
      ld a;
      cin >> a;
      pq.push({a,1});
    }
    
    while (k)
    {
      auto [a,b] = pq.top();
      pq.pop();
      if(k >= b){
        pq.push({a/2, b*2});
        k-=b;
      }else{
        pq.push({a,b-k});
        pq.push({a/2, k*2});
        k=0;
      }
    }

    while (!pq.empty())
    {
      auto [a,b] = pq.top();
      pq.pop();
      if(x <= b){
        cout << fixed << setprecision(20) << a << endl;
        break;
      }else{
        x-=b;
      }
    }
  }
  
}