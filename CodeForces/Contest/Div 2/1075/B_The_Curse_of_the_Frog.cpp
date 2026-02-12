#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll inf = 2e18;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    ll n, x;
    cin >> n >> x;

    ll sum1 = 0;
    ll sum2 = -inf;
    for (int i = 0; i < n; i++)
    {
      ll a,b,c;
      cin >> a >> b >> c;

      ll temp = (b - 1) * a;
      if(sum1 < x){
        sum1 += temp;
      }

      temp = (b * a) - c;
      sum2 = max(sum2, temp);
    }
    
    if(x <= sum1){
      cout << 0 << endl;
    }else if(sum2 <= 0){
      cout << -1 << endl;
    }else{
      ll ans = ((x - sum1) + sum2 - 1) / sum2;
      cout << ans << endl;
    }
  }
  
}