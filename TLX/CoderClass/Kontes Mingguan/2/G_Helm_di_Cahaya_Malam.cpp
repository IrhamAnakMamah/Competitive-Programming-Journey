#include <bits/stdc++.h>
using namespace std;

bool comp(pair<long long,long long> &a, pair<long long,long long> &b){
  return a.second < b.second;
}

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    long long n,p;
    cin >> n >> p;
    vector<pair<long long,long long>> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i].first;
    }

    for (int i = 0; i < n; i++)
    {
      cin >> a[i].second;
    }
    sort(a.begin(), a.end(), comp);
    long long orang = n-1;
    long long ans = p;
    for (int i = 0; i < n; i++)
    {
      auto[x,y] = a[i];
      if(p < y){
        ans += (orang * p);
        orang = 0;
        break;
      }
      ans += y * min(orang, x);
      orang -= min(orang, x);
      if(orang == 0) break;
    }
    if(orang > 0) ans += (orang * p);
    cout << ans << endl;
  }
  

}