#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 4e5+5;
ll n, d;
ll a[MAXN];
int t[4*MAXN];
vector<ll> vals;

void build(int v, int tl, int tr){
  if(tl == tr){
    t[v] = -1; 
  }else{
    int tm = (tl+tr)/2;
    build(v*2, tl, tm);
    build(v*2+1, tm+1, tr);
    t[v] = max(t[v*2], t[v*2+1]);
  }
}

int query_max(int v, int tl, int tr, int l, int r){
  if(l > r){
    return -1;
  }
  if(tl == l && tr == r){
    return t[v];
  }
  int tm = (tl+tr)/2;
  return max(query_max(v*2, tl, tm, l, min(r,tm)), query_max(v*2+1, tm+1, tr, max(l,tm+1), r));
}

void update(int v, int tl, int tr, int pos, int val){
  if(tl == tr){
    t[v] = val;
  }else{
    int tm = (tl+tr)/2;
    if(pos <= tm){
      update(v*2, tl, tm, pos, val);
    }else{
      update(v*2+1, tm+1, tr, pos, val);
    }
    t[v] = max(t[v*2], t[v*2+1]);
  }
}

int get_id(ll val) {
  return lower_bound(vals.begin(), vals.end(), val) - vals.begin();
}

void solve(){
  cin >> n >> d;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    vals.push_back(a[i]);
  }

  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
  
  int m = vals.size();
  build(1, 0, m-1);

  ll ans = 0;
  int l = 0;

  for (int i = 0; i < n; i++)
  {
    ll low = a[i] - d + 1;
    ll high = a[i] + d - 1;
    int idx_l = lower_bound(vals.begin(), vals.end(), low) - vals.begin();
    int idx_r = upper_bound(vals.begin(), vals.end(), high) - vals.begin() - 1;
    int konflik = query_max(1, 0, m-1, idx_l, idx_r);

    if (konflik != -1) {
      l = max(l, konflik + 1);
    }
    ans += (i - l + 1);

    update(1, 0, m-1, get_id(a[i]), i);
  }

  cout << ans << endl;
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
  
}