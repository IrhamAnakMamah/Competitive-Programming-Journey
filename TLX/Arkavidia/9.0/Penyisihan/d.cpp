#include <bits/stdc++.h>
using namespace std;

set<int> ans;
using ll = long long;

void f(int lab1, int lab2, multiset<int> &a, multiset<int> &b, int x){
  if(x == 5){
    ans.insert(lab1);
    return;
  }

  multiset<int> cache;
  if(x&1){
    cache = a;
    for(auto u : cache){
      a.erase(a.find(u));
      b.emplace(u);
      int res = min(lab1, u);
      f(lab1 - res, lab2 + res, a, b, x+1);
      a.emplace(u);
      b.erase(b.find(u));
    }
  }else{
    cache = b;
    for(auto u : cache){
      b.erase(b.find(u));
      a.emplace(u);
      int res = min(lab2, u);
      f(lab1 + res, lab2 - res, a, b, x+1);
      b.emplace(u);
      a.erase(a.find(u));
    }
  }
}

void solve(){
  int n, m;
  cin >> n >> m;

  multiset<int> pertama;
  multiset<int> kedua;

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    pertama.emplace(x);
  }
  for (int i = 0; i < m; i++)
  {
    int x;
    cin >> x;
    kedua.emplace(x);
  }
  
  f(1000, 1000, pertama, kedua, 1);
  // for(auto x : ans){
  //   cout << x << " ";
  // }
  cout << ans.size() << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;

  while (t--)
  {
    solve();
  }
  
  return 0;
}
