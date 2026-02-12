#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 1e3+5;
const ll mod = 998244353;
ll a[MAXN];
int ans;
int n;

int kkk = 0;

void f(int idx, vector<int> &cache){
  // cout << kkk << endl;
  kkk++;
  if(idx == n){
    return;
  }

  if(cache.size() == 2){
    ll temp = cache.back() + cache.front();
    for (int i = idx; i < n; i++)
    {
      if(temp == a[i]){
        cache.push_back(a[i]);
        temp += cache[cache.size() - 2];
      }
    }
    ans += ((cache.size() - 2) % mod);
    // for(auto x : cache){
    //   cout << x << " ";
    // }
    // cout << endl;
    while (cache.size() > 2)
    {
      cache.pop_back();
    }
  }else{
    // ambil
    cache.push_back(a[idx]);
    f(idx+1, cache);
    cache.pop_back();
    f(idx+1, cache);
  }
}

void solve(){
  kkk = 0;
  ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  vector<int> cache;
  f(0,cache);
  cout << ans << endl;
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