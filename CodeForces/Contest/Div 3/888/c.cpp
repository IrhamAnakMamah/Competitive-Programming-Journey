#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  int idx1 = -1;
  int cnt1 = 0;
  int x = a[n-1];
  
  for (int i = n-1; i >= 0; i--) {
    if(a[i] == x){
      cnt1++;
    }
    if(cnt1 == k){
      idx1 = i;
      break;
    }
  }

  int idx2 = -1;
  int cnt2 = 0;
  int y = a[0];

  if (y == x) {
      if (idx1 != -1) cout << "Yes" << endl;
      else cout << "No" << endl;
      return;
  }

  for (int i = 0; i < n; i++) {
    if(a[i] == y){
      cnt2++;
    }
    if(cnt2 == k){
      idx2 = i;
      break;
    }
  }

  if(idx1 != -1 && idx2 != -1 && idx2 < idx1){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}