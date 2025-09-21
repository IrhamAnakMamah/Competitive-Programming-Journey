#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const int MAXN = 1e5+7;
ll n,m;
ll a[MAXN];
ll t[4*MAXN];

void build(int v, int tl, int tr){
  if(tl == tr){
    t[v] = a[tl]; 
  }else{
    int tm = (tl+tr)/2;
    build(v*2, tl, tm);
    build(v*2+1, tm+1, tr);
    t[v] = t[v*2] + t[v*2+1];
  }
}

ll sum(int v, int tl, int tr, int l, int r){
  if(l > r){
    return 0;
  }
  if(tl == l && tr == r){
    return t[v];
  }
  int tm = (tl+tr)/2;
  return sum(v*2, tl, tm, l, min(r,tm)) + sum(v*2+1, tm+1, tr, max(l,tm+1), r);
}

void update(int v, int tl, int tr, int pos, ll val){
  if(tl == tr){
    t[v] = val;
  }else{
    int tm = (tl+tr)/2;
    if(pos <= tm){
      update(v*2, tl, tm, pos, val);
    }else{
      update(v*2+1, tm+1, tr, pos, val);
    }
    t[v] = t[v*2] + t[v*2+1];
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
      cout << sum(1,0,n-1, b, c-1) << endl;
    }
  }
  
}