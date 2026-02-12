#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  ll ans = 0;
  int B = sqrt(n);
  for (int x = 1; x <= B; x++) {
    for (int k = 0; k < n; k++) {      
      ll off = (ll)x * a[k];
      ll i = k - off;

      if (i >= 0 && i < n) {
        if(a[(int)i] == x){
          ans++;
        }
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (a[i] <= B) continue;

    for (int j = 1; ; j++)
    {
      ll temp = i + (ll)a[i] * j;
      if(temp >= n) break;

      if(a[(int)temp] == j) ans++;
    }
  }

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