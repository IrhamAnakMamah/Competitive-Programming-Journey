#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;

  map<pair<int,int>, int> cache;
  int ans = 0;

  auto cek = [&] (int a, int b){
    return !(cache[{a,b}] != 0 || cache[{a+1, b}] != 0 || cache[{a, b+1}] != 0 || cache[{a+1,b+1}] != 0);
  };

  for (int i = 0; i < m; i++)
  {
    int x,y;
    cin >> x >> y;
    x--,y--;
    if(x + 1 == n || y + 1 == n){
      continue;
    }
    bool ok = cek(x, y);
    if(ok){
      ans++;
      cache[{x, y}] = 1;
      cache[{x+1, y}] = 1;
      cache[{x, y+1}] = 1;
      cache[{x+1, y+1}] = 1;
    }
  }
  cout << ans << endl;
}