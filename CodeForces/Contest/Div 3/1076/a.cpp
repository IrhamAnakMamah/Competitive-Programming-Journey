#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n, s, x;
  cin >> n >> s >> x;

  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    sum += a;
  }
  
  if((s - sum) % x == 0 && sum <= s){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }

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