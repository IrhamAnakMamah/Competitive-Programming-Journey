#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n, k;
  cin >> n >> k;

  int sum = 0;
  int time = 0;
  int i = 0;
  while (sum < k)
  {
    sum += n + i;
    time++;
    i++;
  }
  
  cout << time-1 << endl; 
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
