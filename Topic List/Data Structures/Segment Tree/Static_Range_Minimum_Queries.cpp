#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int a[MAXN];
int t[MAXN * 4];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(v*2, tl, tm);
    build(v*2+1, tm+1, tr);
    t[v] = min(t[v*2], t[v*2+1]);
  }
}

int sum(int v, int tl, int tr, int l, int r) {
  if (l > r) 
    return INT_MAX;
  if (l == tl && r == tr) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  return min(sum(v*2, tl, tm, l, min(r, tm)), sum(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
  if (tl == tr) {
    t[v] = new_val;
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(v*2, tl, tm, pos, new_val);
    else
      update(v*2+1, tm+1, tr, pos, new_val);
    t[v] = min(t[v*2], t[v*2+1]);
  }
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
    int x,y;
    cin >> x >> y;
    x--, y--;
    cout << sum(1,0,n-1,x,y) << endl;
  }
  

}