#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;
const int MAXN = 2e5+5;
ll a[MAXN];
ll t[MAXN * 4];
ll lazy[MAXN * 4];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(v*2, tl, tm);
    build(v*2+1, tm+1, tr);
    t[v] = max(t[v*2], t[v*2 + 1]);
  }
}

void push(int v) {
  t[v*2] += lazy[v];
  lazy[v*2] += lazy[v];
  t[v*2+1] += lazy[v];
  lazy[v*2+1] += lazy[v];
  lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, ll addend) {
  if (l > r) 
    return;
  if (l == tl && tr == r) {
    t[v] += addend;
    lazy[v] += addend;
  } else {
    push(v);
    int tm = (tl + tr) / 2;
    update(v*2, tl, tm, l, min(r, tm), addend);
    update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
    t[v] = max(t[v*2], t[v*2+1]);
  }
}

ll query(int v, int tl, int tr, int l, int r) {
  if (l > r)
    return -INF;
  if (l == tl && tr == r)
    return t[v];
  push(v);
  int tm = (tl + tr) / 2;
  return max(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main(){
  int n,q;
  cin >> n >> q;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  build(1,0,n-1);
  while (q--)
  {
    int c;
    cin >> c;
    if(c == 1){
      int x,y;
      ll val;
      cin >> x >> y >> val;
      update(1,0,n-1,x-1,y-1,val);
    }else{
      int x;
      cin >> x;
      cout << query(1,0,n-1,x-1,x-1) << endl;
    }
  }
  
}