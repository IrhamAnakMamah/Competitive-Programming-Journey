#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  
  int ans = 0;
  for (int i = 1; i <= 5e5; i++)
  {
    ans+=i;
    int temp = ans;
    if(temp * temp == ans){
      cout << "i : " << i << ", : " << ans << endl;
    }
  }
  
  
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
