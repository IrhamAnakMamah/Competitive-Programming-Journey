#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;

  map<pair<int,int>,int> mp;

  int ans = 0;
  for (int i = 0; i < m; i++)
  {
    int x,y;
    cin >> x >> y;
    if(x==y){
      ans++;
    }else if(mp.find({x,y}) == mp.end()){
      mp[{x,y}]++;
      mp[{y,x}]++;
    }else{
      ans++;
    }
  }
  cout << ans << endl;
}