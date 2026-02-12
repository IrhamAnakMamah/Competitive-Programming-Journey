#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;

  multiset<int> a;
  int x = 0;
  for (int i = 0; i < n; i++)
  {
    int b;
    cin >> b;
    a.insert(b);
    if(i == 0){
      x = b;
    }else{
      x ^= b;
    }
  }

  if(x == 0){
    cout << "NO" << endl;
    return;
  }

  vector<pair<int,int>> ans;

  while (a.size() != 1)
  {
    int x = *a.begin();
    int y = *a.rbegin();
    if(x == y){
      cout << "NO" << endl;
      return;
    }else{
      int temp = x ^ y;
      ans.push_back({x,y});
      a.erase(a.find(x));
      a.erase(a.find(y));
      a.insert(temp);
    }
  }
  cout << "YES" << endl;
  for(auto [x, y] : ans){
    cout << x << " " << y << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve();
  }
  
}