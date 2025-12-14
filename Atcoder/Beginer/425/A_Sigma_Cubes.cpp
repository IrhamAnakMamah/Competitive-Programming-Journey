#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin >> n;

  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    if(i&1){
      ans += (-1 * pow(i,3));
    }else{
      ans += pow(i,3);
    }
  }
  cout << ans << endl;
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
  
}