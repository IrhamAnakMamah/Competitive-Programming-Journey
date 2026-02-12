#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;
int n;
int need = 0;
ll ans = 0;

void depan(int cnt);
void belakang(int cnt);

void depan(int cnt){
  if(cnt == need){
    ll temp = (cnt * 26) % mod;
    ans = (ans + temp) % mod;
  }else{
    depan(cnt+1);
    depan(cnt+1);
  }
}

void solve(){
  cin >> n;
  string s;
  cin >> s;

  need = n - (int)s.length();
  if(need == 0){
    cout << 0 << endl;
    return;
  }

  depan(0);
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
  return 0;
}