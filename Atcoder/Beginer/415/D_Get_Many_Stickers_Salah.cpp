#include <bits/stdc++.h>
using namespace std;

bool op(const pair<int,int> &a, const pair<int,int> &b){
  return (a.second - a.first) > (b.second - b.first);
}

int main(){
  int n,m;
  cin >> n >> m;

  vector<pair<int,int>> a(m);
  for (int i = 0; i < m; i++)
  {
    int x,y;
    cin >> x >> y;
    a[i] = {x,y};
  }

  sort(a.begin(), a.end(), op);

  int bot = 0;
  int kosong = n;
  int ans = 0;

  int j = 0;

  while (j<m)
  {
    auto[x,y] = a[j];
    if(kosong >= x){
      kosong -= x;
      kosong += y;
      ans++;
    }else{
      j++;
    }
  }
  
  cout << ans << endl;
}