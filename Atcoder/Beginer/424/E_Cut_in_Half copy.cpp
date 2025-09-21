#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,m,x;
    cin >> n >> m >> x;

    int k = m;

    map<double,int> mp;
    for (int i = 0; i < n; i++)
    {
      double a;
      cin >> a;
      mp[a]++;
    }

    while(k != 0){
      auto z = mp.end();
      z--;
      auto [x,y] = *z;
      if(y > k){
        double temp = x/2;
        mp[temp] += (k*2); 
        k = 0;
        mp[x] -= k;
      }else{
        double temp = x/2;
        mp[temp] += (y*2);
        k-=y;
        mp[x] = 0;
      }
    }
    int count = 0;
    double ans = 0;
    for(auto x : mp){
      if(count + x.second >= m){
        ans = x.first;
        break;
      }
      count+=x.second;
    }
    cout << ans << endl;
  }
  
}