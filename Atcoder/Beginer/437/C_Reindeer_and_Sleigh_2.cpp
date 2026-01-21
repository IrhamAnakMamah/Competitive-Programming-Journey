#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool comp(pair<ll,ll> &a, pair<ll,ll> &b){
  return (a.first + a.second) < (b.first < b.second);
}

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    vector<pair<ll,ll>> cache(n);
    for (int i = 0; i < n; i++)
    {
      ll x,y;
      cin >> x >> y;
      cache[i] = {x,y};
    }
    
    sort(cache.begin(), cache.end(), comp);
    
    ll sum1 = 0;
    ll sum2 = 0;
    int ans = 0;
    int i = 0;
    int j = n-1;
    while (i <= j)
    {
      if(sum1 == 0 && sum2 == 0){
        sum1 += cache[i].first;
        i++;
      }else if(sum2 < sum1){
        sum2 += cache[j].second;
        j--;
      }else{
        ans++;
        sum1 += cache[i].first;
        i++;
      }
    }
    
    cout << ans + (sum1 <= sum2) << endl;
  }
  
}