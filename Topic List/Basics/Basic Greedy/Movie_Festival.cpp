#include <bits/stdc++.h>
using namespace std;

bool op(const pair<int,int> &a, const pair<int,int> &b){
  return a.second < b.second;
}

int main(){
  int n;
  cin >> n;

  vector<pair<int,int>> a(n);

  for (int i = 0; i < n; i++)
  {
    int x,y;
    cin >> x >> y;

    a[i] = {x,y};
  }

  sort(a.begin(), a.end(), op);

  int ans = 1;

  auto [bawah,atas] = a[0];

  for (int i = 1; i < n; i++)
  {
    auto[x,y] = a[i];

    if(x >= atas){
      bawah = x;
      atas = y;
      ans++;
    }
  }
  cout << ans << endl;
  
}