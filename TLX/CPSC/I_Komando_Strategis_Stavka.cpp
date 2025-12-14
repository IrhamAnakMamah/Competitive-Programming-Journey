#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 2e5+5;
ll a[MAXN];
ll seg[4*MAXN];
ll lazy[4*MAXN];

void build(int node, int l, int r){
  if(l == r){
    seg[node] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(node * 2, l, mid);
  build(node * 2 + 1, mid + 1, r);

  seg[node] = seg[node*2] + seg[node*2+1];
}

void push(int node, int l, int r) {
  if (lazy[node] != 0) {
    int mid = (l + r) / 2;
        
    lazy[node * 2] += lazy[node];
    seg[node * 2] += lazy[node] * (mid - l + 1);

    lazy[node * 2 + 1] += lazy[node];
    seg[node * 2 + 1] += lazy[node] * (r - (mid + 1) + 1);

    lazy[node] = 0;
  }
}

void update(int node, int l, int r, int i, int j, ll value){
  if(l > j || r < i) return;

  if(l >= i && r <= j){
    seg[node] += value * (r - l + 1); 
    lazy[node] += value;
    return;
  }

  push(node, l, r);

  int mid = (l + r) / 2;
  update(node * 2, l, mid, i, j, value);
  update(node * 2 + 1, mid + 1, r, i, j, value);

  seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll query(int node, int l, int r, int i, int j){
  if(l > j || r < i){
      return 0;
  }
  if(l >= i && r <= j){
      return seg[node];
  }
  push(node, l, r);

  int mid = (l + r) / 2;
  ll q1 = query(node * 2, l, mid, i, j);
  ll q2 = query(node * 2 + 1, mid + 1, r, i, j);

  return q1 + q2;
}

int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  build(1, 0, n-1);
  
  int q;
  cin >> q;
  while (q--)
  {
    string s;
    cin >> s;
    int x,y;
    cin >> x >> y;

    x--, y--;
    if(s == "SUM"){
      cout << query(1, 0, n-1, x, y) << endl;
    }else{
      ll c;
      cin >> c;
      update(1, 0, n-1, x, y, c);
    }
  }
  
}