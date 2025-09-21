#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const int MAXN = 1e5+7;
ll n,m;
ll a[MAXN];

pair<ll, ll> t[4*MAXN];

pair<ll, ll> combine(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first < b.first) 
        return a;
    if (b.first < a.first)
        return b;
    return make_pair(a.first, a.second + b.second);
}

void build(ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = make_pair(a[tl], 1);
    } else {
        ll tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

pair<ll, ll> get_max(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r)
        return make_pair(1e9+7, 0);
    if (l == tl && r == tr)
        return t[v];
    ll tm = (tl + tr) / 2;
    return combine(get_max(v*2, tl, tm, l, min(r, tm)), 
                   get_max(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) {
        t[v] = make_pair(new_val, 1);
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

int main(){
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  build(1,0,n-1);
  
  for (int i = 0; i < m; i++)
  {
    ll a,b,c;
    cin >> a >> b >> c;
    if(a == 1){
      update(1, 0, n-1, b, c);
    }else{
      auto[x,y] = get_max(1,0,n-1,b,c-1);
      cout << x << " " << y << endl;
    }
  }
  
}