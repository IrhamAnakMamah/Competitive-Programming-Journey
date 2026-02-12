#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n, k;
  cin >> n >> k;
  
  vector<pair<int,int>> a(n);
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    a[i] = {x, i+1};
  }

  sort(a.begin(), a.end());

  int x = -1;
  int y = -1;
  int z = -1;
  int ans = 0;

  int pw = pow(2, k) - 1;

  for (int i = 1; i < n; i++)
  {
    int temp1 = a[i].first;
    int temp2 = a[i-1].first;
    // cout << temp1 << " " << temp2 << endl;
    temp1 = pw & ~(pw & temp1);
    temp2 = pw & ~(pw & temp2);
    int res = temp1 & temp2;
    // cout << temp1 << " " << temp2 << " " << res << endl;
    int sum = ((res ^ a[i].first) & (res ^ a[i-1].first));
    if(sum >= ans){
      x = a[i].second;
      y = a[i-1].second;
      z = res;
      ans = sum;
    }
  }
  cout << x << " " << y << " " << z << endl;
  
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
  
  return 0;
}
