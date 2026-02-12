#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 2e5 + 5;
ll n, tree[4*MAXN];

void update(int node, int start, int end, int idx, ll val) {
  if (start == end) {
    tree[node] = val; 
    return;
  }
    
  int mid = (start + end) / 2;
  if (idx <= mid) {
    update(2 * node, start, mid, idx, val);
  } else {
    update(2 * node + 1, mid + 1, end, idx, val);
  }
    
  tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

ll query(int node, int start, int end, int l, int r) {
  if (r < start || end < l) {
    return 0;
  }
    
  if (l <= start && end <= r) {
    return tree[node];
  }
    
  int mid = (start + end) / 2;
  ll p1 = query(2 * node, start, mid, l, r);
  ll p2 = query(2 * node + 1, mid + 1, end, l, r);
    
  return max(p1, p2);
}

void solve() {
  cin >> n;
    
  vector<int> h(n);
  for (int i = 0; i < n; i++) cin >> h[i];
    
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
    
  for (int i = 0; i < n; i++) {
    int current_h = h[i];
    ll current_beauty = a[i];
    ll max_prev = query(1, 1, n, 1, current_h - 1);
    ll new_val = max_prev + current_beauty;
    update(1, 1, n, current_h, new_val);
  }
  cout << tree[1] << endl;
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