#include <bits/stdc++.h>
using namespace std;

void solve(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;

  if(c >= a){
    cout << (d >= b ? "No" : "Yes") << endl;
  }else{
    cout << "No" << endl;
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
  
}