#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, k;
  cin >> n >> k;

  ll ans = 0;
  ll temp = 0;
  while (true)
  {
    temp+=1000;
    temp+=k;
    if(temp <= n){
      ans += 1000;
    }else{
      break;
    }
  }
  cout << ans << endl;
}