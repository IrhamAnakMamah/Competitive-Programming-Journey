#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  ll p, q;
  cin >> p >> q;

  if(3 * p < 2 * q){
    cout << "Alice" << endl;
    return;
  }

  if(q > p){
    cout << "Bob" << endl;
  }else{
    cout << "Alice" << endl;
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
  
}